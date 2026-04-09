"""
PORT_Cfg Generator
GUI tool for generating PORT_Cfg.h for NXP S32K MCU
"""

import sys
import json
import argparse
import re
import os
from datetime import datetime
from PyQt6.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QTabWidget, QTableWidget, QComboBox, QCheckBox, QPushButton,
    QFileDialog, QLabel, QHeaderView, QMessageBox, QTableWidgetItem,
    QMenu, QAbstractItemView
)
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QFont, QAction

# ── Paths (relative to this script) ──────────────────────────────────────────

_SCRIPT_DIR   = os.path.dirname(os.path.abspath(__file__))
_HEADER_PATH  = os.path.normpath(os.path.join(_SCRIPT_DIR, '../../src/s32k/include/MCAL/PORT_Cfg.h'))
_PROJECT_PATH = os.path.join(_SCRIPT_DIR, 'port_config.json')

# ── Config value sets (from PORT_Core.h) ─────────────────────────────────────

PORTS = ['A', 'B', 'C', 'D', 'E']
PINS_PER_PORT = 32

DIRECTIONS      = ['OUTPUT', 'INPUT', 'NOTUSED']
INTRP_ENABLES   = ['DISABLE', 'ENABLE']
INTRP_TYPES     = [
    'INRTP_STATUS_FLG_ISF_DISABLED',
    'ISF_FLG_UPON_DMA_RISING_EDGE',
    'ISF_FLG_UPON_DMA_FALLNG_EDGE',
    'ISF_FLG_UPON_DMA_BOTH_EDGES',
    'ISF_FLG_UPON_INTRPT_LOGIC_0',
    'ISF_FLG_UPON_INTRPT_RISING_EDGE',
    'ISF_FLG_UPON_INTRPT_FALLNG_EDGE',
    'ISF_FLG_UPON_INTRPT_BOTH_EDGES',
    'ISF_FLG_UPON_INTRPT_LOGIC_1',
]
LOCK_VALUES     = ['FALSE', 'TRUE']
MUX_VALUES      = ['GPIO', 'ANALOG', 'CHIPSPECIFIC_1', 'CHIPSPECIFIC_2',
                   'CHIPSPECIFIC_3', 'CHIPSPECIFIC_4', 'CHIPSPECIFIC_5', 'CHIPSPECIFIC_6']
ENABLES         = ['DISABLE', 'ENABLE']
PULL_DIRS       = ['PULL_UP', 'PULL_DWN']

# Column indices
COL_PIN, COL_DIR, COL_INTRP_EN, COL_INTRP_TYPE, COL_LOCK, COL_MUX, \
    COL_DRIVE, COL_FILTER, COL_PULL, COL_PULL_DIR = range(10)

COLUMN_HEADERS = [
    'Pin', 'Direction', 'Interrupt', 'Interrupt Type',
    'Lock Reg', 'Pin Mux', 'Drive Strength', 'Passive Filter',
    'Pull Resistor', 'Pull Direction'
]

DEFAULT_CFG = {
    'direction':        'OUTPUT',
    'interrupt_enable': 'DISABLE',
    'interrupt_type':   'INRTP_STATUS_FLG_ISF_DISABLED',
    'lock':             'FALSE',
    'mux':              'GPIO',
    'drive_strength':   'DISABLE',
    'passive_filter':   'DISABLE',
    'pull_resistor':    'DISABLE',
    'pull_direction':   'PULL_UP',
}


# ── Port Tab ──────────────────────────────────────────────────────────────────

class PortTab(QWidget):
    def __init__(self, port_letter: str, parent=None):
        super().__init__(parent)
        self.port_letter = port_letter
        self._build_ui()

    def _build_ui(self):
        layout = QVBoxLayout(self)

        # ── Top bar ──────────────────────────────────────────────────────────
        top = QHBoxLayout()
        self.enable_cb = QCheckBox(f"Enable Port {self.port_letter}")
        self.enable_cb.setFont(QFont("Segoe UI", 10, QFont.Weight.Bold))
        self.enable_cb.stateChanged.connect(self._on_port_toggle)
        top.addWidget(self.enable_cb)
        top.addSpacing(20)
        top.addWidget(QLabel("Bulk set:"))

        for label, col, options in [
            ("Direction", COL_DIR, DIRECTIONS),
            ("Mux", COL_MUX, MUX_VALUES),
            ("Interrupt", COL_INTRP_EN, INTRP_ENABLES),
        ]:
            lbl = QLabel(f"{label}:")
            top.addWidget(lbl)
            combo = QComboBox()
            combo.addItems(options)
            combo.setFixedWidth(160)
            btn = QPushButton("Apply All")
            btn.setFixedWidth(80)
            btn.clicked.connect(lambda _, c=col, cb=combo: self._apply_all(c, cb.currentText()))
            top.addWidget(combo)
            top.addWidget(btn)
            top.addSpacing(10)

        top.addStretch()
        layout.addLayout(top)

        # ── Table ────────────────────────────────────────────────────────────
        self.table = QTableWidget(PINS_PER_PORT, len(COLUMN_HEADERS))
        self.table.setHorizontalHeaderLabels(COLUMN_HEADERS)
        self.table.verticalHeader().setVisible(False)
        self.table.setAlternatingRowColors(True)
        self.table.setSelectionBehavior(QAbstractItemView.SelectionBehavior.SelectRows)
        self.table.setEditTriggers(QAbstractItemView.EditTrigger.NoEditTriggers)
        self.table.setContextMenuPolicy(Qt.ContextMenuPolicy.CustomContextMenu)
        self.table.customContextMenuRequested.connect(self._context_menu)

        hdr = self.table.horizontalHeader()
        hdr.setSectionResizeMode(QHeaderView.ResizeMode.ResizeToContents)
        hdr.setSectionResizeMode(COL_PIN, QHeaderView.ResizeMode.Fixed)
        self.table.setColumnWidth(COL_PIN, 40)

        for row in range(PINS_PER_PORT):
            self._init_row(row)

        layout.addWidget(self.table)
        self._on_port_toggle(Qt.CheckState.Unchecked.value)

    def _make_combo(self, options: list, default: str, row: int, col: int) -> QComboBox:
        cb = QComboBox()
        cb.addItems(options)
        cb.setCurrentText(default)
        self.table.setCellWidget(row, col, cb)
        return cb

    def _init_row(self, row: int):
        # Pin number label (not editable)
        item = QTableWidgetItem(str(row))
        item.setFlags(item.flags() & ~Qt.ItemFlag.ItemIsEditable)
        item.setTextAlignment(Qt.AlignmentFlag.AlignCenter)
        self.table.setItem(row, COL_PIN, item)

        d = DEFAULT_CFG
        self._make_combo(DIRECTIONS,   d['direction'],        row, COL_DIR)
        intrp = self._make_combo(INTRP_ENABLES, d['interrupt_enable'], row, COL_INTRP_EN)
        itype = self._make_combo(INTRP_TYPES,   d['interrupt_type'],   row, COL_INTRP_TYPE)
        self._make_combo(LOCK_VALUES,  d['lock'],             row, COL_LOCK)
        self._make_combo(MUX_VALUES,   d['mux'],              row, COL_MUX)
        self._make_combo(ENABLES,      d['drive_strength'],   row, COL_DRIVE)
        self._make_combo(ENABLES,      d['passive_filter'],   row, COL_FILTER)
        pull = self._make_combo(ENABLES,      d['pull_resistor'],    row, COL_PULL)
        pdir = self._make_combo(PULL_DIRS,    d['pull_direction'],   row, COL_PULL_DIR)

        # Wire up dependency rules
        intrp.currentTextChanged.connect(lambda v, r=row: self._on_intrp_changed(r, v))
        pull.currentTextChanged.connect(lambda v, r=row: self._on_pull_changed(r, v))

        # Apply initial states
        self._on_intrp_changed(row, d['interrupt_enable'])
        self._on_pull_changed(row, d['pull_resistor'])

    def _combo(self, row: int, col: int) -> QComboBox:
        return self.table.cellWidget(row, col)

    def _on_port_toggle(self, state):
        self.table.setEnabled(state == Qt.CheckState.Checked.value or state == 2)

    def _on_intrp_changed(self, row: int, value: str):
        itype = self._combo(row, COL_INTRP_TYPE)
        if itype:
            itype.setEnabled(value == 'ENABLE')
            if value == 'DISABLE':
                itype.setCurrentText('INRTP_STATUS_FLG_ISF_DISABLED')

    def _on_pull_changed(self, row: int, value: str):
        pdir = self._combo(row, COL_PULL_DIR)
        if pdir:
            pdir.setEnabled(value == 'ENABLE')

    def _apply_all(self, col: int, value: str):
        for row in range(PINS_PER_PORT):
            cb = self._combo(row, col)
            if cb:
                cb.setCurrentText(value)

    def _context_menu(self, pos):
        row = self.table.rowAt(pos.y())
        col = self.table.columnAt(pos.x())
        if row < 0 or col <= COL_PIN:
            return
        cb = self._combo(row, col)
        if not cb:
            return
        current_val = cb.currentText()

        menu = QMenu(self)
        action = menu.addAction(f'Apply "{current_val}" to all pins in this column')
        action.triggered.connect(lambda: self._apply_all(col, current_val))
        menu.exec(self.table.viewport().mapToGlobal(pos))

    # ── Serialization ─────────────────────────────────────────────────────────

    def get_pin_config(self, pin: int) -> dict:
        def val(col):
            cb = self._combo(pin, col)
            return cb.currentText() if cb else ''
        return {
            'direction':        val(COL_DIR),
            'interrupt_enable': val(COL_INTRP_EN),
            'interrupt_type':   val(COL_INTRP_TYPE),
            'lock':             val(COL_LOCK),
            'mux':              val(COL_MUX),
            'drive_strength':   val(COL_DRIVE),
            'passive_filter':   val(COL_FILTER),
            'pull_resistor':    val(COL_PULL),
            'pull_direction':   val(COL_PULL_DIR),
        }

    def set_pin_config(self, pin: int, cfg: dict):
        mapping = [
            (COL_DIR,        'direction',        DIRECTIONS),
            (COL_INTRP_EN,   'interrupt_enable', INTRP_ENABLES),
            (COL_INTRP_TYPE, 'interrupt_type',   INTRP_TYPES),
            (COL_LOCK,       'lock',             LOCK_VALUES),
            (COL_MUX,        'mux',              MUX_VALUES),
            (COL_DRIVE,      'drive_strength',   ENABLES),
            (COL_FILTER,     'passive_filter',   ENABLES),
            (COL_PULL,       'pull_resistor',    ENABLES),
            (COL_PULL_DIR,   'pull_direction',   PULL_DIRS),
        ]
        for col, key, options in mapping:
            v = cfg.get(key, DEFAULT_CFG[key])
            cb = self._combo(pin, col)
            if cb and v in options:
                cb.setCurrentText(v)

    def get_config(self) -> dict:
        return {
            'enabled': self.enable_cb.isChecked(),
            'pins': [self.get_pin_config(p) for p in range(PINS_PER_PORT)],
        }

    def set_config(self, cfg: dict):
        self.enable_cb.setChecked(cfg.get('enabled', False))
        for pin, pcfg in enumerate(cfg.get('pins', [])):
            self.set_pin_config(pin, pcfg)


# ── Main Window ───────────────────────────────────────────────────────────────

class MainWindow(QMainWindow):
    def __init__(self, output_path: str = None, project_path: str = None,
                 import_path: str = None):
        super().__init__()
        self.setWindowTitle("PORT_Cfg Generator  —  NXP S32K")
        self.setMinimumSize(1280, 720)
        self._output_path = output_path
        self._build_ui()
        # Startup load priority: saved project > import existing header > defaults
        if project_path and os.path.isfile(project_path):
            self._load_project_from(project_path)
        elif import_path and os.path.isfile(import_path):
            self._import_header_from(import_path)

    def _build_ui(self):
        central = QWidget()
        self.setCentralWidget(central)
        layout = QVBoxLayout(central)

        self.tabs = QTabWidget()
        self.port_tabs: dict[str, PortTab] = {}
        for port in PORTS:
            tab = PortTab(port)
            self.tabs.addTab(tab, f"  Port {port}  ")
            self.port_tabs[port] = tab
        layout.addWidget(self.tabs)

        # ── Button bar ───────────────────────────────────────────────────────
        btn_bar = QHBoxLayout()

        import_btn = QPushButton("Import  PORT_Cfg.h")
        import_btn.clicked.connect(self._import_header)

        save_btn = QPushButton("Save Project  (JSON)")
        save_btn.clicked.connect(self._save_project)

        load_btn = QPushButton("Load Project  (JSON)")
        load_btn.clicked.connect(self._load_project)

        gen_btn = QPushButton("  Generate  PORT_Cfg.h  ")
        gen_btn.setFont(QFont("Segoe UI", 10, QFont.Weight.Bold))
        gen_btn.setStyleSheet(
            "QPushButton { background-color: #0078d4; color: white; "
            "padding: 8px 24px; border-radius: 5px; }"
            "QPushButton:hover { background-color: #106ebe; }"
        )
        gen_btn.clicked.connect(self._generate)

        btn_bar.addWidget(import_btn)
        btn_bar.addWidget(save_btn)
        btn_bar.addWidget(load_btn)
        btn_bar.addStretch()
        btn_bar.addWidget(gen_btn)
        layout.addLayout(btn_bar)

    # ── Persistence ───────────────────────────────────────────────────────────

    def _all_config(self) -> dict:
        return {p: tab.get_config() for p, tab in self.port_tabs.items()}

    def _set_all_config(self, cfg: dict):
        for p, tab in self.port_tabs.items():
            if p in cfg:
                tab.set_config(cfg[p])

    def _save_project(self):
        path, _ = QFileDialog.getSaveFileName(self, "Save Project", "port_config.json", "JSON Files (*.json)")
        if not path:
            return
        with open(path, 'w') as f:
            json.dump(self._all_config(), f, indent=2)
        QMessageBox.information(self, "Saved", f"Project saved:\n{path}")

    def _load_project(self):
        path, _ = QFileDialog.getOpenFileName(self, "Load Project", "", "JSON Files (*.json)")
        if not path:
            return
        self._load_project_from(path)
        QMessageBox.information(self, "Loaded", f"Project loaded:\n{path}")

    def _load_project_from(self, path: str):
        with open(path) as f:
            cfg = json.load(f)
        self._set_all_config(cfg)

    def _import_header(self):
        path, _ = QFileDialog.getOpenFileName(
            self, "Import PORT_Cfg.h", "", "Header Files (*.h)"
        )
        if not path:
            return
        self._import_header_from(path)
        QMessageBox.information(self, "Imported", f"Configuration imported from:\n{path}")

    def _import_header_from(self, path: str):
        cfg = _parse_header(path)
        self._set_all_config(cfg)

    # ── Code Generation ───────────────────────────────────────────────────────

    def _generate(self):
        if self._output_path:
            path = self._output_path
        else:
            path, _ = QFileDialog.getSaveFileName(
                self, "Save PORT_Cfg.h", "PORT_Cfg.h", "Header Files (*.h)"
            )
            if not path:
                return
        content = _build_header(self._all_config())
        with open(path, 'w', newline='\n') as f:
            f.write(content)
        QMessageBox.information(self, "Generated", f"PORT_Cfg.h written to:\n{path}")


# ── Header Generation ─────────────────────────────────────────────────────────

def _pad(name: str, width: int = 72) -> str:
    """Right-pad a macro name with tabs to align the value column."""
    tabs_needed = max(1, (width - len(name) + 3) // 4)
    return name + '\t' * tabs_needed


def _pin_block(port: str, pin: int, p: dict) -> list[str]:
    pid = f"PORT{port}_{pin}"
    out = [f"\t/*{pid} configuration values Start*/"]

    out.append(f"\t#define\t\t{_pad('PIN_DIR_' + pid)}{p['direction']:<30}/* Cfg values INPUT, OUTPUT, NOTUSED*/")
    out.append(f"\t#define \t{_pad('INTRP_SVC_ON_' + pid)}{p['interrupt_enable']:<30}/* Cfg values ENABLE, DISABLE */")
    out.append("")
    out.append(f"\t#if(INTRP_SVC_ON_{pid} == ENABLE)")
    out.append("")
    out.append(f"\t#define {_pad('INTRP_TYPE_' + pid)}{p['interrupt_type']}")
    out.append("")
    out.append("\t#else")
    out.append("")
    out.append(f"\t#define {_pad('INTRP_TYPE_' + pid)}INRTP_STATUS_FLG_ISF_DISABLED\t\t/*Not to be Modified*/")
    out.append("")
    out.append("\t#endif")
    out.append("")
    out.append(f"\t#define \t{_pad('LOCK_REG_' + pid)}{p['lock']:<30}/* Cfg values TRUE, FALSE */")
    out.append(f"\t#define     {_pad('PIN_MUX_' + pid)}{p['mux']:<30}/* Cfg values Dev. Note 2 */")
    out.append("")
    out.append(f"\t#define \t{_pad('DRIVE_STRNTH_ON_' + pid)}{p['drive_strength']:<30}/* Cfg values ENABLE, DISABLE */")
    out.append(f"\t#define \t{_pad('PASSIVEFIL_ON_' + pid)}{p['passive_filter']:<30}/* Cfg values ENABLE, DISABLE */")
    out.append(f"\t#define \t{_pad('PULL_RESISTOR_ON_' + pid)}{p['pull_resistor']:<30}/* Cfg values ENABLE, DISABLE */")
    out.append("")
    out.append(f"\t#if(PULL_RESISTOR_ON_{pid} == ENABLE)")
    out.append("")
    out.append(f"\t#define \t{_pad('PULLUP_OR_DOWN_ON_' + pid)}{p['pull_direction']:<30}/* Cfg values PULL_UP, PULL_DWN */")
    out.append("")
    out.append("\t#endif")
    out.append(f"\t/*{pid} configuration values End*/")
    out.append("")
    return out


def _build_header(cfg: dict) -> str:
    now = datetime.now().strftime("%d-%b-%Y %H:%M")
    lines = [
        "/*",
        " * PORT_Cfg.h",
        " *",
        f" *  Generated on: {now}",
        " *  Generated by: PORT_Cfg Generator Tool",
        " */",
        "",
        "#ifndef PORT_CFG_H_",
        "#define PORT_CFG_H_",
        "",
        "#include <STRD_Types.h>",
        '#include "Headers.h"',
        "",
    ]

    # Port enable block
    for port in PORTS:
        enabled = "TRUE" if cfg[port]['enabled'] else "FALSE"
        lines.append(f"#define {_pad('ENABLE_PORT_' + port)}{enabled}")
    lines += ["", ""]

    # Per-port pin configs
    for port in PORTS:
        port_cfg = cfg[port]
        lines.append(f"#if(ENABLE_PORT_{port} == TRUE)")
        lines.append("")
        for pin in range(PINS_PER_PORT):
            lines.extend(_pin_block(port, pin, port_cfg['pins'][pin]))
        lines.append(f"#endif /* ENABLE_PORT_{port} */")
        lines += ["", ""]

    lines += ["#endif /* PORT_CFG_H_ */", ""]
    return "\n".join(lines)


# ── Header Parser ────────────────────────────────────────────────────────────

def _parse_header(path: str) -> dict:
    """Parse an existing PORT_Cfg.h and return a config dict compatible with set_all_config."""
    with open(path, encoding='utf-8', errors='ignore') as f:
        text = f.read()

    def find(pattern):
        """Return a dict of {(port, pin): value} for a macro pattern with named groups."""
        return {
            (m.group('port'), int(m.group('pin'))): m.group('val').strip()
            for m in re.finditer(pattern, text)
        }

    # Port enable flags
    port_enabled = {
        m.group('port'): m.group('val').strip()
        for m in re.finditer(
            r'#define\s+ENABLE_PORT_(?P<port>[A-E])\s+(?P<val>\w+)', text
        )
    }

    # Per-pin macros — for macros that appear twice (INTRP_TYPE in if/else),
    # finditer returns them in order; we keep the FIRST occurrence which is
    # the user-configured value inside the #if(INTRP_SVC == ENABLE) branch.
    directions   = find(r'#define\s+PIN_DIR_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    intrp_en     = find(r'#define\s+INTRP_SVC_ON_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    intrp_type   = find(r'#define\s+INTRP_TYPE_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    lock_reg     = find(r'#define\s+LOCK_REG_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    pin_mux      = find(r'#define\s+PIN_MUX_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    drive_str    = find(r'#define\s+DRIVE_STRNTH_ON_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    passive_fil  = find(r'#define\s+PASSIVEFIL_ON_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    pull_res     = find(r'#define\s+PULL_RESISTOR_ON_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')
    pull_dir     = find(r'#define\s+PULLUP_OR_DOWN_ON_PORT(?P<port>[A-E])_(?P<pin>\d+)\s+(?P<val>\w+)')

    cfg = {}
    for port in PORTS:
        pins = []
        for pin in range(PINS_PER_PORT):
            key = (port, pin)
            pins.append({
                'direction':        directions .get(key, DEFAULT_CFG['direction']),
                'interrupt_enable': intrp_en   .get(key, DEFAULT_CFG['interrupt_enable']),
                'interrupt_type':   intrp_type .get(key, DEFAULT_CFG['interrupt_type']),
                'lock':             lock_reg   .get(key, DEFAULT_CFG['lock']),
                'mux':              pin_mux    .get(key, DEFAULT_CFG['mux']),
                'drive_strength':   drive_str  .get(key, DEFAULT_CFG['drive_strength']),
                'passive_filter':   passive_fil.get(key, DEFAULT_CFG['passive_filter']),
                'pull_resistor':    pull_res   .get(key, DEFAULT_CFG['pull_resistor']),
                'pull_direction':   pull_dir   .get(key, DEFAULT_CFG['pull_direction']),
            })
        cfg[port] = {
            'enabled': port_enabled.get(port, 'FALSE') == 'TRUE',
            'pins': pins,
        }
    return cfg


# ── Entry point ───────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(description="PORT_Cfg Generator for NXP S32K")
    parser.add_argument("--output",  "-o", metavar="PATH", default=_HEADER_PATH,
                        help="Output path for PORT_Cfg.h (default: relative to script)")
    parser.add_argument("--project", "-p", metavar="PATH", default=_PROJECT_PATH,
                        help="JSON project file to load on startup (default: relative to script)")
    args, _ = parser.parse_known_args()

    app = QApplication(sys.argv)
    app.setStyle("Fusion")
    window = MainWindow(
        output_path=args.output,
        project_path=args.project,
        import_path=_HEADER_PATH,   # always try to import existing header as fallback
    )
    window.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
