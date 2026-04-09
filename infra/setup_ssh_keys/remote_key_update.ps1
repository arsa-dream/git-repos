# ============================================================
# Remote Key Update Script
# Run this on the REMOTE machine after copying from USB
# It will: detect USB, copy key, fix permissions, delete from USB
# ============================================================

# ---- Helper functions for colored output --------------------
function Print-Header  { param($msg) Write-Host "`n============================================================" -ForegroundColor Cyan
                                     Write-Host " $msg" -ForegroundColor Cyan
                                     Write-Host "============================================================" -ForegroundColor Cyan }
function Print-Step    { param($msg) Write-Host "`n$msg" -ForegroundColor Cyan }
function Print-OK      { param($msg) Write-Host "  [OK]      $msg" -ForegroundColor Green }
function Print-Info    { param($msg) Write-Host "  [INFO]    $msg" -ForegroundColor Gray }
function Print-Warn    { param($msg) Write-Host "  [WARNING] $msg" -ForegroundColor Yellow }
function Print-Error   { param($msg) Write-Host "  [ERROR]   $msg" -ForegroundColor Red }
function Print-Fix     { param($msg) Write-Host "  [FIX]     $msg" -ForegroundColor Magenta }
function Print-Divider {             Write-Host "------------------------------------------------------------" -ForegroundColor DarkGray }
function Exit-WithError {
    param($msg, $fixes)
    Write-Host ""
    Write-Host "============================================================" -ForegroundColor Red
    Write-Host " FAILED" -ForegroundColor Red
    Write-Host "============================================================" -ForegroundColor Red
    Print-Error $msg
    Write-Host ""
    Write-Host "  How to fix:" -ForegroundColor Yellow
    foreach ($fix in $fixes) { Print-Fix $fix }
    Write-Host "============================================================" -ForegroundColor Red
    Write-Host ""
    Write-Host " Press Enter to exit..." -ForegroundColor White
    Read-Host
    exit 1
}
# -------------------------------------------------------------

Print-Header "Remote Key Update Script - S32K144 Robot Framework"

# ============================================================
# STEP 1 - Detect USB drive containing the key
# ============================================================
Print-Step "[1/4] Detecting USB drive with key file..."

$usbDrive = $null
$drives = @("D","E","F","G","H","I","J","K")

foreach ($d in $drives) {
    $keyPath = "${d}:\id_ed25519"
    if (Test-Path $keyPath) {
        $usbDrive = $d
        Print-OK "Key file found on drive ${d}:\"
        Print-Info "Full path: $keyPath"
        break
    }
}

if ($null -eq $usbDrive) {
    Exit-WithError "Private key file (id_ed25519) was not found on any USB drive (D: through K:)." @(
        "Make sure the USB drive is inserted correctly.",
        "Check the drive letter in File Explorer.",
        "Make sure setup_ssh_keys.ps1 was run on the S32K144 machine first.",
        "The key file should be named exactly: id_ed25519 (no extension).",
        "If needed, re-run setup_ssh_keys.ps1 on the S32K144 machine to copy again."
    )
}

# ============================================================
# STEP 2 - Create .ssh folder if it doesn't exist
# ============================================================
Print-Step "[2/4] Preparing .ssh folder..."

$sshFolder = "$env:USERPROFILE\.ssh"
if (-not (Test-Path $sshFolder)) {
    try {
        New-Item -ItemType Directory -Force -Path $sshFolder -ErrorAction Stop | Out-Null
        Print-OK ".ssh folder created at $sshFolder"
    } catch {
        Exit-WithError "Could not create .ssh folder at $sshFolder" @(
            "Make sure you have write permissions to your user profile folder.",
            "Try creating it manually: mkdir $sshFolder",
            "Then run this script again."
        )
    }
} else {
    Print-Info ".ssh folder already exists at $sshFolder"
}

# ============================================================
# STEP 3 - Copy key from USB to .ssh folder
# ============================================================
Print-Step "[3/4] Copying private key from USB to .ssh folder..."

$sourcePath = "${usbDrive}:\id_ed25519"
$destPath   = "$sshFolder\id_ed25519"

# Warn if key already exists
if (Test-Path $destPath) {
    Print-Warn "An existing private key was found at $destPath"
    Print-Warn "It will be replaced with the new key from USB."
}

try {
    Copy-Item $sourcePath $destPath -Force -ErrorAction Stop
    Print-OK "Private key copied to $destPath"
} catch {
    Exit-WithError "Failed to copy the private key from USB to .ssh folder." @(
        "Check that the USB drive is still inserted.",
        "Check you have write access to: $sshFolder",
        "Try manually: Copy-Item '$sourcePath' '$destPath'",
        "Then run this script again."
    )
}

# Fix permissions on the key file
Print-Info "Setting secure permissions on the key file..."
try {
    $result = icacls $destPath /inheritance:r /grant:r "$env:USERNAME`:F" 2>&1
    if ($LASTEXITCODE -eq 0) {
        Print-OK "Key file permissions set correctly."
        Print-Info "Only $env:USERNAME can access this key file."
    } else {
        Print-Warn "Could not set permissions automatically."
        Print-Fix "Run manually: icacls `"$destPath`" /inheritance:r /grant:r `"$env:USERNAME`:F`""
    }
} catch {
    Print-Warn "Permission command failed: $_"
    Print-Fix "Run manually: icacls `"$destPath`" /inheritance:r /grant:r `"$env:USERNAME`:F`""
}

# ============================================================
# STEP 4 - Delete key from USB drive
# ============================================================
Print-Step "[4/4] Deleting private key from USB drive..."

try {
    Remove-Item $sourcePath -Force -ErrorAction Stop
    Print-OK "Private key deleted from USB drive."
    Print-Info "USB drive is now safe to remove."
} catch {
    Print-Warn "Could not automatically delete the key from USB."
    Print-Warn "IMPORTANT: Please delete it manually to keep your key secure!"
    Print-Fix "Run: Remove-Item '${usbDrive}:\id_ed25519' -Force"
    Print-Fix "Or delete it manually in File Explorer from ${usbDrive}:\"
}

# Also delete remote_key_update.ps1 from USB if present
$usbScript = "${usbDrive}:\remote_key_update.ps1"
if (Test-Path $usbScript) {
    try {
        Remove-Item $usbScript -Force -ErrorAction Stop
        Print-Info "remote_key_update.ps1 deleted from USB drive."
    } catch {
        Print-Warn "Could not delete remote_key_update.ps1 from USB."
        Print-Fix "Delete manually from ${usbDrive}:\"
    }
}

# ============================================================
# VERIFY - Quick connectivity test
# ============================================================
Print-Divider
Print-Step "Verifying key file is in place..."

if (Test-Path $destPath) {
    $keyContent = Get-Content $destPath -First 1
    if ($keyContent -like "*OPENSSH*") {
        Print-OK "Key file verified and looks correct."
    } else {
        Print-Warn "Key file exists but content looks unexpected."
        Print-Fix "Make sure the correct key was copied from the S32K144 machine."
    }
} else {
    Exit-WithError "Key file not found at destination after copy." @(
        "Something went wrong during the copy step.",
        "Try manually: Copy-Item '${usbDrive}:\id_ed25519' '$destPath'",
        "Then run this script again."
    )
}

# ============================================================
# SUMMARY
# ============================================================
Write-Host ""
Write-Host "============================================================" -ForegroundColor Green
Write-Host " KEY UPDATE COMPLETE - Remote machine is ready!" -ForegroundColor Green
Write-Host "============================================================" -ForegroundColor Green
Write-Host ""
Write-Host "  Your remote machine is now configured to trigger" -ForegroundColor Cyan
Write-Host "  S32K144 tests on the target machine." -ForegroundColor Cyan
Write-Host ""
Write-Host "  To run tests, open PowerShell and run:" -ForegroundColor White
Print-Divider
Write-Host "  ssh -i `"$env:USERPROFILE\.ssh\id_ed25519`" -o StrictHostKeyChecking=no -p 2222 HP@49.205.216.70" -ForegroundColor Yellow
Print-Divider
Write-Host ""
Write-Host "  This will automatically:" -ForegroundColor White
Write-Host "    1. Connect to the S32K144 machine securely" -ForegroundColor Gray
Write-Host "    2. Start the P&E GDB server" -ForegroundColor Gray
Write-Host "    3. Run all register tests from test_cases.csv" -ForegroundColor Gray
Write-Host "    4. Return pass/fail result to this machine" -ForegroundColor Gray
Write-Host ""
Write-Host "  NOTE: Make sure S32K144 board is connected before running!" -ForegroundColor Cyan
Print-Divider
Write-Host ""
Write-Host " Press Enter to exit..." -ForegroundColor White
Read-Host
