@echo off
:: ============================================================
:: Launcher for remote_key_update.ps1
:: Double-click this file on the remote machine to run setup
:: ============================================================
powershell -ExecutionPolicy Bypass -File "%~dp0remote_key_update.ps1"
