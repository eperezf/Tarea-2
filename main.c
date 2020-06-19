//main.c 

#include "main.h"
#include "lista.h"

int main (int argc, char **argv){
	firstload = 1;
	char* data[5];
	while(menu !=9){

		//Menu principal
		if (menu==0){
			if (firstload == 0){
				//Lemme see dem errors
				printf("\e[1;1H\e[2J");
			}
			firstload = 0;
			printf("Panel de control (%i)\n", menu);
			printf("===================\n");
			printf("1) Abrir archivo de clientes\n");
			printf("2) Agregar cliente\n");
			printf("3) Eliminar cliente\n");
			printf("4) Buscar cliente\n");
			printf("5) Agregar transacción\n");
			printf("6) Deshacer última transacción\n");
			printf("7) Listar clientes por última transacción\n");
			printf("8) Listar clientes por cantidad de dinero\n");
			printf("9) Salir\n");
			printf("50) Imprimir listado de clientes\n");
			printf("===================\n");
			if (loaded == 1){
				printf("Archivo abierto!");
				printf("===================\n");
			}
			printf("Ingrese opción: ");
			scanf("%d", &menu);
		}

		//Carga de archivo
		else if (menu == 1){
			printf("\e[1;1H\e[2J");
			printf("Abrir archivo de clientes\n");
			printf("===================\n");
			printf("Escriba la ruta del archivo: ");
			scanf("%s", &filename);
			crear_lista(&filename, &lista);
			menu = 0;
		}

		//Agregar Cliente
		else if (menu == 2){
			for(int i=0;i<5;i++){
      	data[i]=malloc(sizeof(char)*50);
      }
			printf("\e[1;1H\e[2J");
			printf("Agregar cliente\n");
			printf("===================\n");
			printf("Nombre: ");
			scanf("%s", data[0]);
			printf("Apellido: ");
			scanf("%s", data[1]);
			printf("Email: ");
			scanf("%s", data[2]);
			printf("Género (Male o Female):");
			scanf("%s", data[3]);
			printf("Dirección: ");
			scanf(" %[^\n]s", data[4]);
			agregar_elemento_lista(&lista, data[0], data[1], data[2], data[3], data[4]);
			menu=0;
		}

		//Eliminar Cliente
		else if (menu == 3){
			printf("\e[1;1H\e[2J");
			printf("Eliminar cliente\n");
			printf("===================\n");
		}

		//Buscar Cliente
		else if (menu == 4){
			printf("\e[1;1H\e[2J");
			printf("Buscar cliente\n");
			printf("===================\n");
		}

		//Agregar Transacción
		else if (menu == 5){
			printf("\e[1;1H\e[2J");
			printf("Agregar transacción\n");
			printf("===================\n");
		}

		//Deshacer última Transacción
		else if (menu == 6){
			printf("\e[1;1H\e[2J");
			printf("Deshacer última transacción\n");
			printf("===================\n");
		}

		//Generar lista de cilentes por última transacción
		else if (menu == 7){
			printf("\e[1;1H\e[2J");
			printf("Listar clientes con transacciones recientes\n");
			printf("===================\n");
		}

		//Generar lista de cilentes por dinero
		else if (menu == 8){
			printf("\e[1;1H\e[2J");
			printf("Listar clientes ordenados por dinero\n");
			printf("===================\n");
		}

		//Salir
		else if (menu == 9){
			printf("\e[1;1H\e[2J");
			printf("Listar clientes ordenados por dinero\n");
			printf("===================\n");
		}

		else if (menu == 50){
			printf("\e[1;1H\e[2J");
			printf("DEBUG! Listar clientes\n");
			printf("===================\n");
			listar_lista(&lista);
			sleep(4);
			menu = 0;
			sleep(1);
		}
	};
	return 0;
}


