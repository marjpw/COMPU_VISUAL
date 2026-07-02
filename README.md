# Laboratorio de Computación Visual - Proyecto OpenGL

Este repositorio contiene el código fuente para el modelo 3D desarrollado con OpenGL y C++.

## Instrucciones de Compilación y Ejecución
Para ejecutar este proyecto en Windows (Tener MinGW), abrir una terminal en la raíz de la carpeta del proyecto y ejecutar el siguiente comando:

```powershell
g++ EC1.cpp -o Proyecto.exe -I"./include" -L"./lib" -DFREEGLUT_STATIC -lfreeglut_static -lopengl32 -lglu32 -lwinmm -lgdi32
```
Y luego, para abrir nuestra figura 3D
```
.\Proyecto.exe
```
