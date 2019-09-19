cd command
rmdir /s /q ..\build
del ..\build\Bomber_Man.exe
md ..\build
make  
start ..\build\Bomber_Man.exe
//pause