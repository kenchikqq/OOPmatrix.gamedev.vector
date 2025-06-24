@echo off
echo Попытка компиляции библиотеки математических классов...

REM Попытка найти и использовать компилятор Visual Studio
for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
  set InstallDir=%%i
)

if exist "%InstallDir%\VC\Auxiliary\Build\vcvars64.bat" (
    echo Найден Visual Studio, инициализация среды...
    call "%InstallDir%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
    echo Компиляция с помощью cl.exe...
    cl /EHsc /std:c++14 Finaldz.cpp Complex.cpp Vector3D.cpp Matrix.cpp Fraction.cpp /Fe:math_library.exe
    if errorlevel 0 (
        echo Компиляция успешна!
        echo Запуск программы...
        math_library.exe
    ) else (
        echo Ошибка компиляции
    )
) else (
    echo Visual Studio не найден
    echo Попытка использовать g++...
    g++ --version >nul 2>&1
    if errorlevel 0 (
        g++ -std=c++11 -o math_library.exe Finaldz.cpp Complex.cpp Vector3D.cpp Matrix.cpp Fraction.cpp
        if errorlevel 0 (
            echo Компиляция с g++ успешна!
            echo Запуск программы...
            math_library.exe
        ) else (
            echo Ошибка компиляции с g++
        )
    ) else (
        echo Компилятор не найден
        echo Проверьте, что у вас установлен Visual Studio или MinGW
    )
)

pause 