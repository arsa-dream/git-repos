@echo off
:: ============================================================
:: Remote Trigger Launcher
:: Double-click to trigger S32K144 tests and download reports
:: ============================================================
powershell -ExecutionPolicy Bypass -File "%~dp0remote_trigger.ps1"
