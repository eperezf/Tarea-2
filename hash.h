#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lista.h"

typedef struct Hash{
    int key;
    List* list;
}Hash;

Hash* crear_hash();
int hash_data(char* nombre);
void agregar_elemento_hash(Hash* hash,int key, List* list);
void remover_elemento_hash(Hash* hash, int key);

void buscar_por_id(Hash* hash, int id);
void buscar_por_nombre(Hash* hash, char* nombre);
void buscar_por_apellido(Hash* hash, char* apellido);

