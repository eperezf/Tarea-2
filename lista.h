//lista.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct p {
	int id;
	char nombre[50];
	char apellido[50];
	char email[50];
	char genero[50];
	char direccion[200];
	struct p *next;
};

char filename;
int loaded;

void crear_lista(const char * filename, struct p **lista);

void agregar_elemento_lista();

void eliminar_elemento_lista();

void listar_lista(struct p **lista);