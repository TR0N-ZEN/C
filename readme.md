To transform source code to an executable program a compiler is needed.  

# on Microsoft Windows
One is a chocolatey package
Downloadable via powershell with:
```ps1
choco install mingw
#choco install Cygwin # provides posix api for windows
```

If you haven't installed chocolatey
```ps1
Set-ExecutionPolicy Bypass -Scope Process -Force;
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072;
iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'));
```

# on Linux distibutions with apt
```bash
sudo apt install gcc
```
