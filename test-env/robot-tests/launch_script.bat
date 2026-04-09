@echo off
setlocal

:: ============================================================
:: CONFIGURATION
:: ============================================================
set GDB_SERVER="C:\NXP\S32DS_ARM_v2.2\eclipse\plugins\com.pemicro.debug.gdbjtag.pne_4.4.6.201912192052\win32\pegdbserver_console.exe"
set DEVICE=NXP_S32K1xx_S32K144F512M15
set SERVER_PORT=7224
set GDBMI_PORT=6224

set VENV_ACTIVATE=C:\Users\HP\.venv\Scripts\activate.bat
set TEST_SUITE=D:\git-repos\infra\setup_ssh_keys\tests\s32k_register_tests.robot
set OUTPUT_DIR=D:\git-repos\infra\setup_ssh_keys\results

:: Color helper macros
:: Usage: call :PRINT_INFO "message"
::        call :PRINT_OK "message"
::        call :PRINT_WARN "message"
::        call :PRINT_ERROR "message"

powershell -Command "Write-Host '============================================================' -ForegroundColor Cyan"
powershell -Command "Write-Host ' S32K144 Robot Framework Launch Script' -ForegroundColor Cyan"
powershell -Command "Write-Host '============================================================' -ForegroundColor Cyan"
echo.

:: ============================================================
:: STEP 1: Check if S32K144 board is connected
:: ============================================================
powershell -Command "Write-Host '[1/5] Checking for S32K144 board via OpenSDA...' -ForegroundColor Cyan"
powershell -Command "Get-PnpDevice | Where-Object {$_.FriendlyName -like '*OpenSDA*' -or $_.FriendlyName -like '*S32K*'} | Select-Object Status, FriendlyName" 2>nul
if errorlevel 1 (
    powershell -Command "Write-Host '[WARNING] Could not verify board connection. Proceeding anyway...' -ForegroundColor Yellow"
)

:: ============================================================
:: STEP 2: Kill any existing GDB server instances
:: ============================================================
powershell -Command "Write-Host '[2/5] Cleaning up any existing GDB server instances...' -ForegroundColor Cyan"
taskkill /IM pegdbserver_console.exe /F >nul 2>&1
timeout /t 1 /nobreak >nul

:: ============================================================
:: STEP 3: Start P&E GDB Server in background
:: ============================================================
powershell -Command "Write-Host '[3/5] Starting P&E GDB Server...' -ForegroundColor Cyan"
start "PEGDBServer" %GDB_SERVER% -startserver -device=%DEVICE% -serverport=%SERVER_PORT% -gdbmiport=%GDBMI_PORT%

:: ============================================================
:: STEP 4: Wait for server to be ready (with 10 second timeout)
:: ============================================================
powershell -Command "Write-Host '[4/5] Waiting for GDB Server to be ready (max 10 seconds)...' -ForegroundColor Cyan"
set WAIT_COUNT=0
set WAIT_START=%TIME%

:WAIT_LOOP
set /a WAIT_COUNT+=1
if %WAIT_COUNT% GTR 5 (
    echo.
    powershell -Command "Write-Host '============================================================' -ForegroundColor Red"
    powershell -Command "Write-Host ' [ERROR] GDB Server failed to start.' -ForegroundColor Red"
    powershell -Command "Write-Host ' [ERROR] Wait started : %WAIT_START%' -ForegroundColor Red"
    powershell -Command "Write-Host ' [ERROR] Wait ended   : %TIME%' -ForegroundColor Red"
    powershell -Command "Write-Host ' [ERROR] Total attempts: 5' -ForegroundColor Red"
    powershell -Command "Write-Host '------------------------------------------------------------' -ForegroundColor Red"
    powershell -Command "Write-Host ' Please check:' -ForegroundColor Yellow"
    powershell -Command "Write-Host '   1. S32K144 board is connected via USB' -ForegroundColor Yellow"
    powershell -Command "Write-Host '   2. OpenSDA drivers are installed' -ForegroundColor Yellow"
    powershell -Command "Write-Host '   3. No other GDB server is running' -ForegroundColor Yellow"
    powershell -Command "Write-Host '============================================================' -ForegroundColor Red"
    taskkill /IM pegdbserver_console.exe /F >nul 2>&1
    taskkill /FI "WINDOWTITLE eq PEGDBServer" /F >nul 2>&1
    echo.
    if not "%1"=="--no-browser" set /p DUMMY=Press Enter to exit...
    exit /b 1
)
powershell -Command "$t = New-Object Net.Sockets.TcpClient; try { $r = $t.BeginConnect('localhost', %SERVER_PORT%, $null, $null); $w = $r.AsyncWaitHandle.WaitOne(2000); if ($w -and !$t.Client.Poll(0, [System.Net.Sockets.SelectMode]::SelectError)) { $t.EndConnect($r); exit 0 } else { exit 1 } } catch { exit 1 } finally { $t.Close() }"
if errorlevel 1 (
    powershell -Command "Write-Host '    Still waiting... [Attempt %WAIT_COUNT%/5] [Time: %TIME%]' -ForegroundColor Yellow"
    goto WAIT_LOOP
)
powershell -Command "Write-Host '    GDB Server is ready on port %SERVER_PORT%! [Time: %TIME%]' -ForegroundColor Green"
powershell -Command "Write-Host '    Total wait: started %WAIT_START% - ended %TIME%' -ForegroundColor Green"

:: ============================================================
:: STEP 5: Activate venv and run Robot Framework tests
:: ============================================================
powershell -Command "Write-Host '[5/5] Activating virtual environment and running tests...' -ForegroundColor Cyan"
call %VENV_ACTIVATE%
if errorlevel 1 (
    echo.
    powershell -Command "Write-Host '============================================================' -ForegroundColor Red"
    powershell -Command "Write-Host ' [ERROR] Failed to activate virtual environment.' -ForegroundColor Red"
    powershell -Command "Write-Host ' [ERROR] Check path: %VENV_ACTIVATE%' -ForegroundColor Red"
    powershell -Command "Write-Host '============================================================' -ForegroundColor Red"
    taskkill /IM pegdbserver_console.exe /F >nul 2>&1
    echo.
    if not "%1"=="--no-browser" set /p DUMMY=Press Enter to exit...
    exit /b 1
)

robot --outputdir %OUTPUT_DIR% %TEST_SUITE%
set ROBOT_EXIT=%ERRORLEVEL%

:: ============================================================
:: CLEANUP: Kill GDB Server after tests complete
:: ============================================================
echo.
powershell -Command "Write-Host '[Done] Stopping P&E GDB Server...' -ForegroundColor Cyan"
taskkill /FI "WINDOWTITLE eq PEGDBServer" /F >nul 2>&1
taskkill /IM pegdbserver_console.exe /F >nul 2>&1
powershell -Command "Write-Host '[Done] GDB Server stopped.' -ForegroundColor Cyan"

:: ============================================================
:: RESULT: Report test outcome
:: ============================================================
echo.
powershell -Command "Write-Host '============================================================' -ForegroundColor Cyan"
if %ROBOT_EXIT% EQU 0 (
    powershell -Command "Write-Host '  TEST RESULT: ALL TESTS PASSED' -ForegroundColor Green"
) else (
    powershell -Command "Write-Host '  TEST RESULT: SOME TESTS FAILED' -ForegroundColor Red"
)
powershell -Command "Write-Host '  Results saved to: %OUTPUT_DIR%' -ForegroundColor Cyan"
powershell -Command "Write-Host '============================================================' -ForegroundColor Cyan"

:: Open report in browser and wait for input (interactive mode only)
if "%1"=="--no-browser" goto END

start "" "%OUTPUT_DIR%\report.html"
echo.
powershell -Command "Write-Host '============================================================' -ForegroundColor Cyan"
powershell -Command "Write-Host '  Press Enter to exit...' -ForegroundColor White"
powershell -Command "Write-Host '============================================================' -ForegroundColor Cyan"
set /p DUMMY=

:END
exit /b %ROBOT_EXIT%
