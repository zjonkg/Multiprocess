# Gestión de Procesos en C++

Este proyecto en C++ demuestra cómo crear y gestionar múltiples procesos utilizando la función `fork()` en sistemas Unix/Linux. Cada proceso hijo interactúa de manera independiente, añadiendo datos a un vector local y seleccionando un elemento aleatorio de este.

## Descripción del programa

El programa realiza los siguientes pasos:

1. Solicita al usuario la cantidad de procesos hijos (`N`) que desea crear.
2. Crea `N` procesos hijos usando la llamada al sistema `fork()`.
3. Cada proceso hijo:
   - Solicita al usuario un nombre para añadir a un vector local de nombres.
   - Selecciona aleatoriamente un nombre del vector local y lo imprime.
   - Finaliza.
4. El proceso padre espera que todos los procesos hijos finalicen antes de imprimir un mensaje indicando que todos han terminado.

**Nota:** El vector de nombres no es compartido entre los procesos. Cada proceso hijo tiene su propia copia del vector y las modificaciones realizadas no afectan al vector del proceso padre ni al de los demás hijos.

## Archivos

- `main.cpp`: El archivo principal con el código fuente del programa.

## Compilación y ejecución

### Requisitos

- Un compilador compatible con C++ (como `g++`).
- Un sistema operativo basado en Unix/Linux (que soporte las llamadas a `fork()`, `wait()`, etc.).

### Compilación

Para compilar el programa, ejecuta el siguiente comando en la terminal:

```bash
g++ main.cpp -o gestion_procesos
