//lista.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct List{
    int id;
    char nombre[50];
    char apellido[50];
    char email[50];
    char genero[8];
    char direccion[128];
    //Pile* transacciones;
    struct List* next;
}List;


char filename;
int loaded;

List *crear_lista();
void agregar_elemento_lista(List** list, int id, char* nombre, char* apellido, char* email, char* genero, char* direccion/*, Pile* transacciones*/);
void remover_elemento_lista (List** list, char* nombre, char* apellido);
void listar_lista(List** list);

