# ============================================================
# SSH Key Rotation & Setup Script
# Run this in PowerShell as Administrator on the S32K144 machine
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
    Write-Host " SETUP FAILED" -ForegroundColor Red
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

Print-Header "SSH Key Rotation & Setup Script - S32K144 Robot Framework"

# ============================================================
# STEP 1 - Check if running as Administrator
# ============================================================
Print-Step "[1/6] Checking Administrator privileges..."
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
if (-not $isAdmin) {
    Exit-WithError "This script must be run as Administrator." @(
        "Close this window.",
        "Find PowerShell in Start Menu.",
        "Right-click it and select Run as Administrator.",
        "Run the script again."
    )
}
Print-OK "Running as Administrator."

# ============================================================
# STEP 2 - Generate new SSH key pair (no passphrase)
# ============================================================
Print-Step "[2/6] Generating new SSH key pair..."

if (Test-Path "$env:USERPROFILE\.ssh\id_ed25519") {
    Remove-Item "$env:USERPROFILE\.ssh\id_ed25519" -Force
    Print-Info "Old private key removed."
}
if (Test-Path "$env:USERPROFILE\.ssh\id_ed25519.pub") {
    Remove-Item "$env:USERPROFILE\.ssh\id_ed25519.pub" -Force
    Print-Info "Old public key removed."
}

if (-not (Test-Path "$env:USERPROFILE\.ssh")) {
    New-Item -ItemType Directory -Force -Path "$env:USERPROFILE\.ssh" | Out-Null
    Print-Info ".ssh folder created."
}

cmd /c "echo y | ssh-keygen -t ed25519 -C ""s32k-robot-framework"" -f ""$env:USERPROFILE\.ssh\id_ed25519"" 2>&1" | Out-Null

if (-not (Test-Path "$env:USERPROFILE\.ssh\id_ed25519")) {
    Print-Warn "Automatic key generation failed. Trying interactive mode..."
    Print-Warn "Press Enter twice when prompted for passphrase."
    ssh-keygen -t ed25519 -C "s32k-robot-framework" -f "$env:USERPROFILE\.ssh\id_ed25519"
}

if (Test-Path "$env:USERPROFILE\.ssh\id_ed25519") {
    Print-OK "New SSH key pair generated successfully."
} else {
    Exit-WithError "SSH key generation failed. No key file was created." @(
        "Make sure OpenSSH client is installed on this machine.",
        "Run: Get-WindowsCapability -Online | Where-Object Name -like 'OpenSSH.Client*'",
        "If not installed run: Add-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0",
        "Then run this script again."
    )
}

# ============================================================
# STEP 3 - Read the new public key
# ============================================================
Print-Step "[3/6] Reading new public key..."
try {
    $pubKey = Get-Content "$env:USERPROFILE\.ssh\id_ed25519.pub" -ErrorAction Stop
    Print-OK "Public key read successfully."
    Print-Info "Key: $pubKey"
} catch {
    Exit-WithError "Could not read the public key file." @(
        "Check if the file exists at: $env:USERPROFILE\.ssh\id_ed25519.pub",
        "Try running manually: ssh-keygen -t ed25519 -f $env:USERPROFILE\.ssh\id_ed25519",
        "Then run this script again."
    )
}

# ============================================================
# STEP 4 - Update administrators_authorized_keys
# ============================================================
Print-Step "[4/6] Updating authorized keys with command restriction..."
$authKeysPath = "$env:ProgramData\ssh\administrators_authorized_keys"
$restrictedEntry = "command=""cmd /c D:\git-repos\infra\setup_ssh_keys\launch_script.bat"" $pubKey"

try {
    Set-Content -Force -Path $authKeysPath -Value $restrictedEntry -ErrorAction Stop
    Print-OK "Authorized keys file updated."
    Print-Info "Key is restricted to run launch_script.bat only."
    Print-Info "No other commands can be executed with this key."
} catch {
    Exit-WithError "Failed to update the authorized keys file. Access was denied." @(
        "This script must be run as Administrator (see Step 1).",
        "Make sure the folder exists: $env:ProgramData\ssh\",
        "If missing run: New-Item -Force -Path '$authKeysPath' -ItemType File",
        "Then run this script again as Administrator."
    )
}

# ============================================================
# STEP 5 - Fix permissions on authorized keys file
# ============================================================
Print-Step "[5/6] Fixing file permissions on authorized keys..."
$result = icacls $authKeysPath /inheritance:r /grant "SYSTEM:(F)" /grant "Administrators:(F)" 2>&1
if ($LASTEXITCODE -eq 0) {
    Print-OK "Permissions set correctly."
    Print-Info "Only SYSTEM and Administrators can access this file."
} else {
    Exit-WithError "Failed to set permissions on authorized keys file." @(
        "Run this manually as Administrator:",
        "icacls `"$authKeysPath`" /inheritance:r /grant `"SYSTEM:(F)`" /grant `"Administrators:(F)`"",
        "Then restart SSH: Restart-Service sshd"
    )
}

# ============================================================
# STEP 6 - Restart SSH service and verify
# ============================================================
Print-Step "[6/6] Restarting SSH service and verifying..."
try {
    Restart-Service sshd -ErrorAction Stop
    Start-Sleep -Seconds 2
    $sshdStatus = Get-Service sshd
    if ($sshdStatus.Status -eq "Running") {
        Print-OK "SSH service restarted and is running."
    } else {
        Exit-WithError "SSH service is installed but not running after restart." @(
            "Try starting it manually: Start-Service sshd",
            "Check Windows Event Viewer for sshd errors.",
            "Make sure port 2222 is not used by another app.",
            "Run: netstat -ano | findstr :2222"
        )
    }
} catch {
    Exit-WithError "Could not restart the SSH service. Access denied or service not found." @(
        "Make sure OpenSSH Server is installed:",
        "Get-WindowsCapability -Online | Where-Object Name -like 'OpenSSH.Server*'",
        "If not installed: Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0",
        "Then run: Start-Service sshd",
        "Then run this script again as Administrator."
    )
}

Print-Divider
$portTest = Test-NetConnection -ComputerName 127.0.0.1 -Port 2222 -WarningAction SilentlyContinue
if ($portTest.TcpTestSucceeded) {
    Print-OK "SSH is listening on port 2222 and ready for connections."
} else {
    Exit-WithError "SSH service is running but port 2222 is not reachable." @(
        "Check sshd_config has Port 2222 (not commented out):",
        "Get-Content `"$env:ProgramData\ssh\sshd_config`" | findstr Port",
        "If it shows #Port 2222 run:",
        "(Get-Content `"$env:ProgramData\ssh\sshd_config`") -replace '#Port 2222', 'Port 2222' | Set-Content `"$env:ProgramData\ssh\sshd_config`"",
        "Then: Restart-Service sshd"
    )
}

# ============================================================
# SUMMARY
# ============================================================
Write-Host ""
Write-Host "============================================================" -ForegroundColor Green
Write-Host " SETUP COMPLETE - All steps passed successfully!" -ForegroundColor Green
Write-Host "============================================================" -ForegroundColor Green

# ============================================================
# USB KEY TRANSFER
# ============================================================
Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host " Step A: Copy Private Key to USB Drive" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "  Insert your USB drive now, then enter its drive letter." -ForegroundColor White
Write-Host "  Example: E or F or G" -ForegroundColor Gray
Write-Host ""
$driveLetter = Read-Host "  Enter USB drive letter (or press Enter to skip)"

if ($driveLetter -ne "") {
    $usbPath = "${driveLetter}:\id_ed25519"
    $usbBatPath = "${driveLetter}:\remote_key_update.ps1"
    $localBatPath = "D:\git-repos\infra\setup_ssh_keys\remote_key_update.ps1"
    try {
        if (-not (Test-Path "${driveLetter}:\")) {
            Exit-WithError "Drive ${driveLetter}: is not accessible." @(
                "Make sure the USB drive is inserted correctly.",
                "Check the drive letter in File Explorer.",
                "Run the script again with the correct drive letter."
            )
        }
        # Copy private key to USB
        Copy-Item "$env:USERPROFILE\.ssh\id_ed25519" $usbPath -Force -ErrorAction Stop
        Print-OK "Private key copied to $usbPath"

        # Copy remote_key_update.ps1 to USB
        if (Test-Path $localBatPath) {
            Copy-Item $localBatPath $usbBatPath -Force -ErrorAction Stop
            Print-OK "remote_key_update.ps1 copied to $usbBatPath"
            Print-Info "Run remote_key_update.ps1 on the remote machine to complete setup."
        } else {
            Print-Warn "remote_key_update.ps1 not found at: $localBatPath"
            Print-Fix "Copy it manually to the USB drive from your project folder."
        }

        # Copy run_remote_key_update.bat launcher to USB
        $localLauncherPath = "D:\git-repos\infra\setup_ssh_keys\run_remote_key_update.bat"
        $usbLauncherPath   = "${driveLetter}:\run_remote_key_update.bat"
        if (Test-Path $localLauncherPath) {
            Copy-Item $localLauncherPath $usbLauncherPath -Force -ErrorAction Stop
            Print-OK "run_remote_key_update.bat launcher copied to $usbLauncherPath"
            Print-Info "Remote user just needs to double-click run_remote_key_update.bat"
        } else {
            Print-Warn "run_remote_key_update.bat not found at: $localLauncherPath"
            Print-Fix "Copy it manually to the USB drive from your project folder."
        }

        # Copy remote_trigger.ps1 to USB
        $localTriggerPath = "D:\git-repos\infra\setup_ssh_keys\remote_trigger.ps1"
        $usbTriggerPath   = "${driveLetter}:\remote_trigger.ps1"
        if (Test-Path $localTriggerPath) {
            Copy-Item $localTriggerPath $usbTriggerPath -Force -ErrorAction Stop
            Print-OK "remote_trigger.ps1 copied to $usbTriggerPath"
        } else {
            Print-Warn "remote_trigger.ps1 not found at: $localTriggerPath"
            Print-Fix "Copy it manually to the USB drive from your project folder."
        }

        # Copy run_remote_trigger.bat launcher to USB
        $localTriggerBat = "D:\git-repos\infra\setup_ssh_keys\run_remote_trigger.bat"
        $usbTriggerBat   = "${driveLetter}:\run_remote_trigger.bat"
        if (Test-Path $localTriggerBat) {
            Copy-Item $localTriggerBat $usbTriggerBat -Force -ErrorAction Stop
            Print-OK "run_remote_trigger.bat copied to $usbTriggerBat"
            Print-Info "After key setup, remote user double-clicks run_remote_trigger.bat to run tests"
        } else {
            Print-Warn "run_remote_trigger.bat not found at: $localTriggerBat"
            Print-Fix "Copy it manually to the USB drive from your project folder."
        }

        Print-Warn "Remember to delete the key from USB after running remote_key_update.bat!"
        Write-Host ""
        Write-Host "  On the remote machine:" -ForegroundColor White
        Write-Host "    1. Insert USB drive" -ForegroundColor Yellow
        Write-Host "    2. Double-click run_remote_key_update.bat  (first time only)" -ForegroundColor Yellow
        Write-Host "    3. Double-click run_remote_trigger.bat     (to run tests anytime)" -ForegroundColor Yellow
        Write-Host "    4. Reports will download automatically to Desktop\S32K144_Reports" -ForegroundColor Yellow
    } catch {
        Print-Error "Failed to copy files to USB drive: $_"
        Print-Fix "Try manually: Copy-Item '$env:USERPROFILE\.ssh\id_ed25519' '${driveLetter}:\id_ed25519'"
    }
} else {
    Print-Warn "USB copy skipped. You can copy manually later:"
    Write-Host "    Copy-Item '$env:USERPROFILE\.ssh\id_ed25519' 'E:\id_ed25519'" -ForegroundColor Yellow
}

# ============================================================
# NEXT STEPS
# ============================================================
Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host " Step B: Test Connection from Remote Machine" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "  On remote machine - fix permissions:" -ForegroundColor White
Write-Host "    icacls `"`$env:USERPROFILE\.ssh\id_ed25519`" /inheritance:r /grant:r `"`$env:USERNAME`:F`"" -ForegroundColor Yellow
Write-Host ""
Write-Host "  On remote machine - delete key from USB:" -ForegroundColor White
Write-Host "    Remove-Item 'E:\id_ed25519' -Force" -ForegroundColor Yellow
Write-Host ""
Write-Host "  On remote machine - test SSH connection:" -ForegroundColor White
Write-Host "    ssh -i `"`$env:USERPROFILE\.ssh\id_ed25519`" -o StrictHostKeyChecking=no -p 2222 HP@49.205.216.70" -ForegroundColor Yellow
Write-Host ""
Write-Host "  NOTE: Make sure S32K144 board is connected before testing!" -ForegroundColor Cyan
Print-Divider
Write-Host ""
Write-Host " Press Enter to exit..." -ForegroundColor White
Read-Host
