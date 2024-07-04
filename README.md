# Hash table, Linked List and Tree structure

## Compilar

```
make
```

## Recompilar

```
make clean && make
```

## Ejecutar

```
./riddler input.txt output.txt
```

## Comparar respuesta

Script de Python que les permite comparar su respuesta con la respuesta correcta. Para ejecutarlo, deben tener instalado Python 3.6 o superior:
```
python check_output.py correc_output.txt student_output.txt
```

## Debugeamos leaks con:

```shell
valgrind --leak-check=full --show-leak-kinds=all ./riddler input.txt output.txt
```

## Debugeamos errores con:

```shell
valgrind --track-origins=yes ./riddler input.txt output.txt
```
