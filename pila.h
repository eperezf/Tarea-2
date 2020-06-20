#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Pile{
    int monto;
    int codigo;
    struct Pile* next;
}Pile;

Pile* crear_pila();

int agregar_elemento_pila(Pile** pile, int monto, int codigo);

void remover_elemento_pila(Pile** pile);

void eliminar_pila(Pile** pile);