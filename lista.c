//lista.c

#include "lista.h"

void crear_lista(const char * filename, struct p **lista){
	char line[255];
	int linelength;
	FILE *fp;
	if ((fp = fopen(filename, "r"))){
		fp = fopen(filename, "r");
		printf("Archivo abierto correctamente. Guardando en memoria...\n");
		loaded = 1;
		fgets(line, 255, fp);
		int id;
		char* nombre;
    char* apellido;
    char* email;
    char* genero;
    char* direccion;
		char aux[1000];
		struct p *ultimo = NULL;
		while(fgets(aux,999,fp)){
			id = atoi(strtok(aux,"\t"));
    	nombre = strtok(NULL,"\t");
    	apellido = strtok(NULL,"\t");
    	email = strtok(NULL,"\t");
			genero = strtok(NULL,"\t");
			direccion = strtok(NULL, "\n");
			struct p *persona = malloc(sizeof(struct p));
			persona->id = id;
      strcpy(persona->nombre, nombre);
      strcpy(persona->apellido, apellido);
      strcpy(persona->email, email);
    	strcpy(persona->genero, genero);
			strcpy(persona->direccion, direccion);

			if (*lista==NULL){
          *lista = persona;
          persona->next = NULL;
          ultimo = persona;
        }
        else {
          ultimo->next = persona;
          persona->next = NULL;
          ultimo = persona;
        }
		}
		sleep(1);
  }
	else{
		printf("\nERROR: El archivo no existe\n");
		loaded = 0;
		sleep(1);
	}
}

void listar_lista(struct p **lista){
	struct p *nodo = *lista;
  while(nodo->next != NULL){
  	printf("%d %s %s %s %s %s\n",nodo->id, nodo->nombre, nodo->apellido, nodo->email, nodo->genero, nodo->direccion);
    nodo = nodo->next;
  }
	printf("%d %s %s %s %s %s\n",nodo->id, nodo->nombre, nodo->apellido, nodo->email, nodo->genero, nodo->direccion);
}

void agregar_elemento_lista(struct p **lista, char * nombre, char * apellido, char * email, char * genero, char * direccion){
	struct p *nuevo = malloc(sizeof(struct p));
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->apellido, apellido);
	strcpy(nuevo->email, email);
	strcpy(nuevo->genero, genero);
	strcpy(nuevo->direccion, direccion);
	nuevo->next = NULL;
	if (*lista == NULL){
		*lista = nuevo;
		nuevo->id = 1;
	}
	else {
		struct p *nodo = *lista;
  	while(nodo->next != NULL){
    	nodo = nodo->next;
  	}
		nuevo->id = nodo->id+1;
		nodo->next = nuevo;
		nodo = nodo->next;
	}
	sleep(2);
}