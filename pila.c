#include "pila.h"

Pile* crear_pila(){
    Pile* pile = malloc(sizeof(Pile));
    return pile ;
}

int agregar_elemento_pila(Pile** pile, int monto, int codigo){
	Pile *nuevo = malloc(sizeof(Pile));
	nuevo->monto = monto;
	nuevo-> codigo =codigo;
	if (*pile == NULL){
		*pile = nuevo;
	}

}

void remover_elemento_pila(Pile** pile){

}



