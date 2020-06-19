#include "hash.h"


Hash* crear_hash(int size){
	Hash* hash;
  hash = malloc(sizeof(Hash)*5);
  for (int i = 0; i < 5; i++){
  	hash[i].key=i;
  	hash[i].list=crear_lista();
  }
  return hash;
}

int hash_data(char* apellido){
	int hash = apellido[0] % 5;
	return hash;
}

void agregar_elemento_hash(Hash* hash, int key, List* list){
	//Unused
}

void remover_elemento_hash(Hash* hash, int key){
    free(hash[key].list);
}

void buscar_por_id(Hash* hash, int id){
	List* nodo = malloc(sizeof(List));;
	for (int i = 0; i < 5; i++)
	{
		nodo = hash[i].list;
		while(nodo->next != NULL){
			if(nodo->id == id){
				printf("\e[1;1H\e[2J");
				printf("USUARIO ENCONTRADO:\n");
				printf("ID: %i\n", nodo->id);
				printf("Nombre: %s\n", nodo->nombre);
				printf("Apellido: %s\n", nodo->apellido);
				printf("Email: %s\n", nodo->email);
				printf("Género: %s\n", nodo->genero);
				printf("Dirección: %s\n", nodo->direccion);
				
			}
			else {
			}
			nodo = nodo->next;
		}
	}
	sleep(5);
}

void buscar_por_nombre(Hash* hash, char* nombre){
	List* nodo = malloc(sizeof(List));
	printf("\e[1;1H\e[2J");
	for (int i = 0; i < 5; i++)
	{
		nodo = hash[i].list;
		while(nodo->next != NULL){
			if(strcmp(nodo->nombre, nombre) == 0){
				printf("USUARIO ENCONTRADO:\n");
				printf("ID: %i\n", nodo->id);
				printf("Nombre: %s\n", nodo->nombre);
				printf("Apellido: %s\n", nodo->apellido);
				printf("Email: %s\n", nodo->email);
				printf("Género: %s\n", nodo->genero);
				printf("Dirección: %s\n\n", nodo->direccion);
			}
			nodo = nodo->next;
		}
	}
	sleep(5);
}

void buscar_por_apellido(Hash* hash, char* apellido){
	List* nodo = malloc(sizeof(List));
	nodo = hash[hash_data(apellido)].list;
	printf("\e[1;1H\e[2J");
	while(nodo->next != NULL){
		if(strcmp(nodo->apellido, apellido)==0){
			printf("USUARIO ENCONTRADO:\n");
			printf("ID: %i\n", nodo->id);
			printf("Nombre: %s\n", nodo->nombre);
			printf("Apellido: %s\n", nodo->apellido);
			printf("Email: %s\n", nodo->email);
			printf("Género: %s\n", nodo->genero);
			printf("Dirección: %s\n\n", nodo->direccion);
		}
		nodo = nodo->next;
	}
	sleep(5);
}