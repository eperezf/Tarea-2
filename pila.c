#include "pila.h"

Pile* crear_pila(){
    Pile* pile = malloc(sizeof(Pile));
    return pile ;
}

void agregar_elemento_pila(Pile** pile, int monto, int codigo){
	if (codigo != 101 && codigo != 201){
		printf("El código ingresado no es el correcto.\n");
		sleep(3);
		return;
	}
	printf("Insertando transacción código %i monto $%i\n", codigo, monto);
	Pile *nuevo = malloc(sizeof(Pile));
	nuevo->monto = monto;
	nuevo-> codigo =codigo;
	nuevo->next = *pile;
	*pile = nuevo;
	sleep(3);
}

void remover_elemento_pila(Pile** pile){

}

void listar_pila(Pile** pile){
	printf("Transacciones recientes:\n");
	Pile* actual = malloc(sizeof(Pile));
	actual = *pile;
	while (actual != NULL){
		if (actual->monto != 0){
			if(actual->codigo == 101){
				printf("$%i\n", actual->monto);
			}
			else {
				printf("$-%i\n", actual->monto);
			}
			
		}
		actual = actual->next;	
	};
}



