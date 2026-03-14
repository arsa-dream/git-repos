@echo off
setlocal

:: ============================================================
:: CONFIGURATION
:: ============================================================
set GDB_SERVER="C:\NXP\S32DS_ARM_v2.2\eclipse\plugins\com.pemicro.debug.gdbjtag.pne_4.4.6.201912192052\win32\pegdbserver_console.exe"
set DEVICE=NXP_S32K1xx_S32K144F512M15
set SERVER_PORT=7224
set GDBMI_PORT=6224

set VENV_ACTIVATE=C:\Users\HP\robot-tests\.venv\Scripts\activate.bat
set TEST_SUITE=D:\git-repos\test-env\robot-tests\tests\s32k_register_tests.robot
set OUTPUT_DIR=D:\git-repos\test-env\robot-tests\results

:: ============================================================
:: STEP 1: Start P&E GDB Server in background
:: ============================================================
echo [1/4] Starting P^&E GDB Server...
start "PEGDBServer" %GDB_SERVER% -startserver -device=%DEVICE% -serverport=%SERVER_PORT% -gdbmiport=%GDBMI_PORT%

:: ============================================================
:: STEP 2: Wait for server to be ready (poll port 7224)
:: ============================================================
echo [2/4] Waiting for GDB Server to be ready...
:WAIT_LOOP
timeout /t 2 /nobreak >nul
powershell -Command "try { $t = New-Object Net.Sockets.TcpClient('localhost', %SERVER_PORT%); $t.Close(); exit 0 } catch { exit 1 }"
if errorlevel 1 (
    echo     Still waiting...
    goto WAIT_LOOP
)
echo     GDB Server is ready on port %SERVER_PORT%!

:: ============================================================
:: STEP 3: Activate venv and run Robot Framework tests
:: ============================================================
echo [3/4] Activating virtual environment...
call %VENV_ACTIVATE%

echo [4/4] Running Robot Framework tests...
robot --outputdir %OUTPUT_DIR% %TEST_SUITE%

:: ============================================================
:: STEP 4: Kill GDB Server after tests complete
:: ============================================================
echo.
echo [Done] Stopping P^&E GDB Server...
taskkill /FI "WINDOWTITLE eq PEGDBServer" /F >nul 2>&1
taskkill /IM pegdbserver_console.exe /F >nul 2>&1
echo [Done] GDB Server stopped.

:: ============================================================
:: STEP 5: Open results in browser
:: ============================================================
echo Opening test report...
start "" "%OUTPUT_DIR%\report.html"

echo.
echo ============================================================
echo  All done! Check the report above for results.
echo ============================================================
pause
