import subprocess
import re

GDB_PATH = r"C:\NXP\S32DS_ARM_v2.2\S32DS\build_tools\gcc_v6.3\gcc-6.3-arm32-eabi\bin\arm-none-eabi-gdb.exe"
GDB_SERVER = "localhost:7224"


def write_register(address, value):
    """Write a value to a memory-mapped register on the S32K144."""
    commands = [
        f"target remote {GDB_SERVER}",
        f"set {{unsigned int}}{address} = {value}",
        "quit"
    ]
    _run_gdb(commands)


def read_register(address):
    """Read a value from a memory-mapped register. Returns hex string."""
    commands = [
        f"target remote {GDB_SERVER}",
        f"x/1xw {address}",
        "quit"
    ]
    output = _run_gdb(commands)
    match = re.search(r'0x[0-9a-fA-F]+:\s+(0x[0-9a-fA-F]+)', output)
    if match:
        return match.group(1).lower()
    raise RuntimeError(f"Could not parse GDB output for address {address}:\n{output}")


def _run_gdb(commands):
    args = [GDB_PATH, "--batch"]
    for cmd in commands:
        args += ["--ex", cmd]
    result = subprocess.run(args, capture_output=True, text=True, timeout=15)
    return result.stdout + result.stderr
