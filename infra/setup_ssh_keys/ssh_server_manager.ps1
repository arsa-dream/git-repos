# ============================================================
# SSH Server Manager Script
# Run this in PowerShell as Administrator
# Allows you to Start, Stop or Check SSH server status
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
# -------------------------------------------------------------

function Check-AdminRights {
    $isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
    if (-not $isAdmin) {
        Write-Host ""
        Write-Host "============================================================" -ForegroundColor Red
        Write-Host " ERROR - Administrator privileges required!" -ForegroundColor Red
        Write-Host "============================================================" -ForegroundColor Red
        Print-Error "This script must be run as Administrator."
        Print-Fix "Close this window."
        Print-Fix "Find PowerShell in Start Menu."
        Print-Fix "Right-click it and select Run as Administrator."
        Print-Fix "Run the script again."
        Write-Host "============================================================" -ForegroundColor Red
        Write-Host ""
        Write-Host " Press Enter to exit..." -ForegroundColor White
        Read-Host
        exit 1
    }
}

function Show-Status {
    Print-Step "Current SSH Server Status:"
    Print-Divider
    $sshd = Get-Service sshd -ErrorAction SilentlyContinue
    if ($null -eq $sshd) {
        Print-Error "SSH Server (sshd) is not installed on this machine."
        Print-Fix "Run: Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0"
        return
    }

    if ($sshd.Status -eq "Running") {
        Print-OK "SSH Server is RUNNING on port 2222."
        Print-Info "Startup type: $($sshd.StartType)"
        Print-Info "Remote machines can connect to: HP@49.205.216.70 -p 2222"

        $listening = netstat -ano | findstr ":2222"
        if ($listening) {
            Print-OK "Port 2222 is open and listening."
        } else {
            Print-Warn "Service is running but port 2222 is not detected."
        }
    } elseif ($sshd.Status -eq "Stopped") {
        Print-Warn "SSH Server is STOPPED."
        Print-Info "Startup type: $($sshd.StartType)"
        Print-Info "Remote machines cannot connect until server is started."
    } else {
        Print-Warn "SSH Server status: $($sshd.Status)"
    }
    Print-Divider
}

function Start-SSHServer {
    Print-Step "Starting SSH Server..."
    $sshd = Get-Service sshd -ErrorAction SilentlyContinue
    if ($null -eq $sshd) {
        Print-Error "SSH Server (sshd) is not installed."
        Print-Fix "Run: Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0"
        return
    }
    if ($sshd.Status -eq "Running") {
        Print-Warn "SSH Server is already running."
        Show-Status
        return
    }
    try {
        Start-Service sshd -ErrorAction Stop
        Start-Sleep -Seconds 2
        $status = Get-Service sshd
        if ($status.Status -eq "Running") {
            Print-OK "SSH Server started successfully."
            Print-OK "Remote machines can now connect."
            Print-Info "Connection command for remote machine:"
            Write-Host "    ssh -i `$env:USERPROFILE\.ssh\id_ed25519 -o StrictHostKeyChecking=no -p 2222 HP@49.205.216.70" -ForegroundColor Yellow
        } else {
            Print-Error "SSH Server failed to start. Status: $($status.Status)"
            Print-Fix "Check Windows Event Viewer for sshd errors."
            Print-Fix "Run: Get-EventLog -LogName System -Source sshd -Newest 5"
        }
    } catch {
        Print-Error "Could not start SSH Server: $_"
        Print-Fix "Make sure you are running as Administrator."
    }
}

function Stop-SSHServer {
    Print-Step "Stopping SSH Server..."
    $sshd = Get-Service sshd -ErrorAction SilentlyContinue
    if ($null -eq $sshd) {
        Print-Error "SSH Server (sshd) is not installed."
        return
    }
    if ($sshd.Status -eq "Stopped") {
        Print-Warn "SSH Server is already stopped."
        return
    }
    try {
        Stop-Service sshd -ErrorAction Stop
        Start-Sleep -Seconds 2
        $status = Get-Service sshd
        if ($status.Status -eq "Stopped") {
            Print-OK "SSH Server stopped successfully."
            Print-Info "Remote machines can no longer connect."
        } else {
            Print-Error "SSH Server failed to stop. Status: $($status.Status)"
            Print-Fix "Try: Stop-Service sshd -Force"
        }
    } catch {
        Print-Error "Could not stop SSH Server: $_"
        Print-Fix "Make sure you are running as Administrator."
    }
}

function Set-AutoStart {
    param([bool]$enable)
    if ($enable) {
        Print-Step "Enabling SSH Server auto-start on boot..."
        try {
            Set-Service -Name sshd -StartupType Automatic -ErrorAction Stop
            Print-OK "SSH Server will now start automatically on boot."
        } catch {
            Print-Error "Could not set startup type: $_"
            Print-Fix "Make sure you are running as Administrator."
        }
    } else {
        Print-Step "Disabling SSH Server auto-start on boot..."
        try {
            Set-Service -Name sshd -StartupType Manual -ErrorAction Stop
            Print-OK "SSH Server will no longer start automatically on boot."
            Print-Info "You will need to start it manually when needed."
        } catch {
            Print-Error "Could not set startup type: $_"
            Print-Fix "Make sure you are running as Administrator."
        }
    }
}

# ============================================================
# MAIN MENU
# ============================================================
Check-AdminRights
Print-Header "SSH Server Manager - S32K144 Robot Framework"
Show-Status

while ($true) {
    Write-Host ""
    Write-Host "============================================================" -ForegroundColor Cyan
    Write-Host " What would you like to do?" -ForegroundColor Cyan
    Write-Host "============================================================" -ForegroundColor Cyan
    Write-Host "  [1] Start SSH Server" -ForegroundColor Green
    Write-Host "  [2] Stop SSH Server" -ForegroundColor Yellow
    Write-Host "  [3] Check Status" -ForegroundColor Cyan
    Write-Host "  [4] Enable auto-start on boot" -ForegroundColor Gray
    Write-Host "  [5] Disable auto-start on boot" -ForegroundColor Gray
    Write-Host "  [6] Exit" -ForegroundColor White
    Print-Divider
    $choice = Read-Host "  Enter your choice (1-6)"

    switch ($choice) {
        "1" { Start-SSHServer }
        "2" { Stop-SSHServer }
        "3" { Show-Status }
        "4" { Set-AutoStart -enable $true }
        "5" { Set-AutoStart -enable $false }
        "6" {
            Write-Host ""
            Write-Host " Exiting SSH Server Manager." -ForegroundColor Cyan
            Write-Host ""
            exit 0
        }
        default {
            Print-Warn "Invalid choice. Please enter a number between 1 and 6."
        }
    }
}
