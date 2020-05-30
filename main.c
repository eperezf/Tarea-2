//main.c 

#include "main.h"

int main (int argc, char **argv)
{
	cli(0);

	return 0;
}

void cli(int * menu){
	printf("%i\n", *menu);
	if(menu==0){
		printf("Sistema de administración\n");
		printf("============\n");
		printf("1.- Cargar archivo de clientes\n");
		printf("2.- Agregar cliente\n");
		printf("3.- Eliminar cliente\n");
		printf("4.- Agregar transacción\n");
		printf("5.- Deshacer transacción\n");
		printf("6.- Buscar cliente\n");
		printf("7.- Generar lista de clientes\n");
		printf("==========\n");
		printf("Ingrese una opción: ");
		scanf("%d", &menuOpt);
		printf("%d", menuOpt);
	}	
	else{
	}
}