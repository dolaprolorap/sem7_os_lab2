@echo off
@chcp 65001

cd .\lib
cmake -G "MinGW Makefiles" -B build
cd build
cmake --build . 
cmake --install . --prefix ..\..\utils\lib

cd ..\..\counter
cmake -G "MinGW Makefiles" -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=..\bin
cd build
cmake --build .

cd ..\..
set "relative_path=.\counter\bin"
for %%I in ("%relative_path%") do set "absolute_path=%%~fI"
set "PATH=%PATH%;%absolute_path%"

cd .\utils
cmake -G "MinGW Makefiles" -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=..\bin
cd build
cmake --build .

cd ..\bin
.\main
