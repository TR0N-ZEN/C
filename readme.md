To transform source code to an executable program a compiler is needed.


# on Microsoft Windows

One is a chocolatey package
so if you haven't installed chocolatey, do so with:
```ps1
Set-ExecutionPolicy Bypass -Scope Process -Force;
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072;
iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'));
```

Install `gcc` through powershell with:
```ps1
choco install mingw
#choco install Cygwin # provides posix api for windows
```



# on Linux distibutions with `apt`

```bash
sudo apt install gcc
```



# compile on Linux

```bash
# compile source files
gcc -c foo.c
gcc -c main.c

# link the object files to one executable
gcc -o executable_file foo.o main.o
```

But better go reade `man gcc`.



# use a debugger aka. see what code does

One popular debugger I use has its documentation at https://sourceware.org/gdb/.
