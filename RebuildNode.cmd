@ECHO OFF
IF "%1"=="1" GOTO X86
IF "%1"=="2" GOTO X64

:X86
node-pre-gyp rebuild --target_arch=ia32
exit

:X64
node-pre-gyp rebuild --target_arch=x64
exit