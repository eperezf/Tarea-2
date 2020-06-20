//lista.c

#include "lista.h"

List* crear_lista(){
    List* head = malloc(sizeof(List));
    head=NULL;
    return head;
}

void agregar_elemento_lista(List** list, int id, char* nombre, char* apellido, char* email, char* genero, char* direccion){
	List* nuevo = malloc(sizeof(List));
	nuevo->id = id;
  strcpy(nuevo->nombre,nombre);
  strcpy(nuevo->apellido,apellido);
  strcpy(nuevo->email,email);
  strcpy(nuevo->genero,genero);
  strcpy(nuevo->direccion, direccion);
	nuevo->saldo = 0;
  nuevo->transacciones=crear_pila();
  nuevo->next=NULL;
  if(*list==NULL){
    *list=nuevo;
  }
	else{
  	List* nodo = *list;
  	while(nodo->next != NULL){
    	nodo = nodo->next;
  	}
		nodo->next = nuevo;
		nodo = nodo->next;
  }
}

void remover_elemento_lista(List** list, char* nombre, char* apellido){
	List* nodo = *list;
	List* anterior = NULL;
	List* next = NULL;
	while (nodo->next!= NULL){
		if (!strcmp(nodo->nombre, nombre) && !strcmp(nodo->apellido, apellido)){
			printf("Usuario encontrado. %s %s Eliminando.\n", nombre, apellido);
			

			if (anterior == NULL){
				*list=nodo->next;
			}
			else {
				if (nodo->next == NULL){
					anterior->next = NULL;
				}
				else {
					anterior->next = nodo->next;
				}
			}
			free(nodo);
			nodo = *list;
			sleep(3);
			return;
		}
		else {
		}
		anterior = nodo;
		nodo = nodo->next;
	};
}

void listar_lista(List** list){
	List*nodo = *list;
	printf("%s\n", (*list)->nombre);
  while(nodo->next != NULL){
  	printf("%d %s %s %s %s %s\n",nodo->id, nodo->nombre, nodo->apellido, nodo->email, nodo->genero, nodo->direccion);
    nodo = nodo->next;
  }
	printf("%d %s %s %s %s %s\n",nodo->id, nodo->nombre, nodo->apellido, nodo->email, nodo->genero, nodo->direccion);

}

