@echo off
:: ============================================================
:: Run setup_ssh_keys.ps1 as Administrator
:: Double-click this file to launch the SSH key setup
:: ============================================================

powershell -Command "Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File ""%~dp0setup_ssh_keys.ps1""' -Verb RunAs"
