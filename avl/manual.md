# Compilación y Ejecución del Proyecto

## Requisitos
- Entorno Linux
- Utilidad make instalada
- Compilador adecuado (por ejemplo, g++, gcc, etc.)

## Instrucciones de Compilación y Ejecución

### 1. Compilar el Proyecto para mediciones

Para compilar el proyecto para ejecutar mediciones, se debe ejecutar el siguiente comando en la terminal:

```bash
make clean && make release -j
```
 Seguido de esto, se debe ejecutar el siguiente comando para ejecutar el programa:

```bash
make run
```

### 2. Compilar el Proyecto para prueba de correctitud

Para compilar el proyecto para ejecutar pruebas de correctitud, se debe ejecutar el siguiente comando en la terminal:

```bash
make clean && make release DEFS=-DTEST -j
```
 Seguido de esto, se debe ejecutar el siguiente comando para ejecutar el programa:

```bash
make run
```

### 3. Chequeo de memoria

Para chequear la memoria del programa, se debe ejecutar el siguiente comando en la terminal:

```bash
make clean && make memcheck DEFS=-DTEST -j
```