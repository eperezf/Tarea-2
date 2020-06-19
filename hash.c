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
				printf("ID ENCONTRADO! %s %s\n", nodo->nombre, nodo->apellido);
				return;
				sleep (5);
			}
			else {
				nodo = nodo->next;
			}
		}
	}
	
}

void buscar_por_nombre(Hash* hash, char* nombre){

}

void buscar_por_apellido(List** list, char* apellido){

}