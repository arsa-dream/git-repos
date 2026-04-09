# ============================================================
# Remote Trigger Script
# Run this on the REMOTE machine to:
#   1. Trigger S32K144 tests on the target machine via SSH
#   2. Wait for tests to complete
#   3. Download report.html and log.html automatically
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

# ============================================================
# CONFIGURATION — update these if anything changes
# ============================================================
$TARGET_IP      = "49.205.216.70"
$TARGET_PORT    = "2222"
$TARGET_USER    = "HP"
$PRIVATE_KEY    = "$env:USERPROFILE\.ssh\id_ed25519"
$REMOTE_RESULTS = "D:/git-repos/infra/setup_ssh_keys/results"
$LOCAL_REPORTS  = "$env:USERPROFILE\Desktop\S32K144_Reports"
# -------------------------------------------------------------

Print-Header "Remote Trigger Script - S32K144 Robot Framework"

# ============================================================
# STEP 1 - Check private key exists
# ============================================================
Print-Step "[1/4] Checking SSH private key..."
if (-not (Test-Path $PRIVATE_KEY)) {
    Exit-WithError "Private key not found at: $PRIVATE_KEY" @(
        "Make sure you ran remote_key_update.ps1 to set up the key.",
        "Insert the USB drive with the key and run run_remote_key_update.bat.",
        "Then run this script again."
    )
}
Print-OK "Private key found at $PRIVATE_KEY"

# ============================================================
# STEP 2 - Check SSH connectivity to target machine
# ============================================================
Print-Step "[2/4] Checking connection to target machine..."
$portTest = Test-NetConnection -ComputerName $TARGET_IP -Port $TARGET_PORT -WarningAction SilentlyContinue
if (-not $portTest.TcpTestSucceeded) {
    Exit-WithError "Cannot reach target machine at ${TARGET_IP}:${TARGET_PORT}." @(
        "Make sure the S32K144 machine is powered on.",
        "Make sure the SSH server is running on the target machine.",
        "Run ssh_server_manager.ps1 on the target machine and select [1] Start.",
        "Make sure port 2222 is open on the router.",
        "Check your internet connection."
    )
}
Print-OK "Target machine is reachable at ${TARGET_IP}:${TARGET_PORT}"

# ============================================================
# STEP 3 - Trigger tests via SSH
# ============================================================
Print-Step "[3/4] Triggering S32K144 tests on target machine..."
Print-Info "Connecting to ${TARGET_USER}@${TARGET_IP} on port ${TARGET_PORT}..."
Print-Info "Tests are now running on the target machine. Please wait..."
Print-Divider

# Run tests via SSH — --no-browser prevents launch_script from opening browser
$sshArgs = @(
    "-i", $PRIVATE_KEY,
    "-o", "StrictHostKeyChecking=no",
    "-o", "BatchMode=yes",
    "-p", $TARGET_PORT,
    "${TARGET_USER}@${TARGET_IP}"
)

# Note: authorized_keys restricts to launch_script.bat automatically
# We pass --no-browser so the remote script doesn't try to open a browser
$sshProcess = Start-Process -FilePath "ssh" `
    -ArgumentList $sshArgs `
    -NoNewWindow -Wait -PassThru

$sshExitCode = $sshProcess.ExitCode
Print-Divider

if ($sshExitCode -eq 0) {
    Print-OK "All tests PASSED on target machine!"
} elseif ($sshExitCode -eq 1) {
    Print-Warn "Some tests FAILED on target machine."
    Print-Info "Downloading report for details..."
} else {
    Exit-WithError "SSH connection failed with exit code: $sshExitCode" @(
        "Make sure the S32K144 board is connected to the target machine via USB.",
        "Make sure the SSH server is running on the target machine.",
        "Check that your private key matches the one on the target machine.",
        "Try running ssh_server_manager.ps1 on target machine to verify server status."
    )
}

# ============================================================
# STEP 4 - Download reports via SCP
# ============================================================
Print-Step "[4/4] Downloading test reports from target machine..."

# Create local reports folder with timestamp
$timestamp = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"
$reportFolder = "$LOCAL_REPORTS\$timestamp"
New-Item -ItemType Directory -Force -Path $reportFolder | Out-Null
Print-Info "Saving reports to: $reportFolder"

$scpBase = @(
    "-i", $PRIVATE_KEY,
    "-o", "StrictHostKeyChecking=no",
    "-P", $TARGET_PORT
)

# Download report.html
Print-Info "Downloading report.html..."
$scpReport = Start-Process -FilePath "scp" `
    -ArgumentList ($scpBase + @("${TARGET_USER}@${TARGET_IP}:${REMOTE_RESULTS}/report.html", "$reportFolder\report.html")) `
    -NoNewWindow -Wait -PassThru

if ($scpReport.ExitCode -eq 0) {
    Print-OK "report.html downloaded successfully."
} else {
    Print-Warn "Could not download report.html"
    Print-Fix "Try manually: scp -i $PRIVATE_KEY -P $TARGET_PORT ${TARGET_USER}@${TARGET_IP}:${REMOTE_RESULTS}/report.html $reportFolder\"
}

# Download log.html
Print-Info "Downloading log.html..."
$scpLog = Start-Process -FilePath "scp" `
    -ArgumentList ($scpBase + @("${TARGET_USER}@${TARGET_IP}:${REMOTE_RESULTS}/log.html", "$reportFolder\log.html")) `
    -NoNewWindow -Wait -PassThru

if ($scpLog.ExitCode -eq 0) {
    Print-OK "log.html downloaded successfully."
} else {
    Print-Warn "Could not download log.html"
    Print-Fix "Try manually: scp -i $PRIVATE_KEY -P $TARGET_PORT ${TARGET_USER}@${TARGET_IP}:${REMOTE_RESULTS}/log.html $reportFolder\"
}

# Download output.xml
Print-Info "Downloading output.xml..."
$scpXml = Start-Process -FilePath "scp" `
    -ArgumentList ($scpBase + @("${TARGET_USER}@${TARGET_IP}:${REMOTE_RESULTS}/output.xml", "$reportFolder\output.xml")) `
    -NoNewWindow -Wait -PassThru

if ($scpXml.ExitCode -eq 0) {
    Print-OK "output.xml downloaded successfully."
} else {
    Print-Warn "Could not download output.xml"
}

# ============================================================
# SUMMARY
# ============================================================
Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
if ($sshExitCode -eq 0) {
    Write-Host " TEST RESULT: ALL TESTS PASSED" -ForegroundColor Green
} else {
    Write-Host " TEST RESULT: SOME TESTS FAILED" -ForegroundColor Red
}
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "  Reports saved to:" -ForegroundColor White
Write-Host "  $reportFolder" -ForegroundColor Yellow
Write-Host ""

# Open report in browser
$reportFile = "$reportFolder\report.html"
if (Test-Path $reportFile) {
    Print-OK "Opening report in browser..."
    Start-Process $reportFile
} else {
    Print-Warn "Report file not found. Check the folder manually:"
    Write-Host "  $reportFolder" -ForegroundColor Yellow
}

Print-Divider
Write-Host ""
Write-Host " Press Enter to exit..." -ForegroundColor White
Read-Host
