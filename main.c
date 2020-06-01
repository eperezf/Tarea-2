//main.c 

#include "main.h"
#include "lista.h"

int main (int argc, char **argv)
{
	
	cli(0);
}

void cli(int menu){
	if (menu == 0){
		//printf("\e[1;1H\e[2J");
		printf("Panel de control\n");
		printf("===================\n");
		printf("1) Abrir archivo de clientes\n");
		printf("2) Agregar cliente\n");
		printf("===================\n");
		if (loaded == 1){
			printf("Archivo abierto: %s", &filename);
			printf(".txt\n");
			printf("===================\n");
		}
		printf("Ingrese opción: ");
		scanf("%d", &selected);
		cli(selected);
	}
	if (menu == 1){
		printf("\e[1;1H\e[2J");
		printf("Abrir archivo de clientes\n");
		printf("===================\n");
		printf("Escriba la ruta del archivo: ");
		scanf("%s", &filename);
		crear_lista(&filename, &lista_personas);
	}
	if (menu == 2){
		printf("\e[1;1H\e[2J");
		printf("Agregar cliente\n");
		printf("===================\n");
	}
	
}


