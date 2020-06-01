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
		sleep(5);
  }
	else{
		printf("\nERROR: El archivo no existe\n");
		loaded = 0;
		sleep(1);
	}

}