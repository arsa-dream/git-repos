@echo off
:: ============================================================
:: SSH Server Manager Launcher
:: Double-click to manage SSH server (Start / Stop / Status)
:: ============================================================
powershell -ExecutionPolicy Bypass -Command "Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File \"%~dp0ssh_server_manager.ps1\"' -Verb RunAs"
