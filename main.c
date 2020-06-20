//main.c 

#include "main.h"

int main (int argc, char **argv){
	firstload = 1;
	char nombre[50];
	char apellido[50];
	char email[50];
	char genero[10];
	char direccion[256];
	

	List* list;
	Hash* hash = crear_hash();
	
	while(menu !=9){

		//Menu principal
		if (menu==0){
			if (firstload == 0){
				//Lemme see dem errors
				printf("\e[1;1H\e[2J");
			}
			else {
			}
			firstload = 0;
			printf("Panel de control\n");
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
			/*
			printf("=================== DEBUG OPTIONS:\n");
			printf("50) Imprimir listado de clientes\n");
			printf("51) Hash Name\n");
			*/
			printf("===================\n");
			if (loaded == 1){
				printf("Archivo abierto!\n");
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
			cargar_archivo(&filename, hash);
			menu = 0;
		}

		//Agregar Cliente
		else if (menu == 2){

			printf("\e[1;1H\e[2J");
			printf("Agregar cliente\n");
			printf("===================\n");
			printf("Nombre: ");
			scanf("%s", nombre);
			printf("Apellido: ");
			scanf("%s", apellido);
			printf("Email: ");
			scanf("%s", email);
			printf("Género (Male o Female):");
			scanf("%s", genero);
			printf("Dirección: ");
			scanf(" %[^\n]s", direccion);
			printf("%s %s %s %s %s\n", nombre, apellido, email, genero, direccion);
			agregar_elemento_lista(&hash[hash_data(apellido)].list, free_id, nombre, apellido, email, genero, direccion);
			free_id++;
			menu=0;
		}

		//Eliminar Cliente
		else if (menu == 3){
			printf("\e[1;1H\e[2J");
			printf("Eliminar cliente\n");
			printf("===================\n");
			printf("Nombre: ");
			scanf("%s", nombre);
			printf("Apellido: ");
			scanf("%s", apellido);
			remover_elemento_lista(&hash[hash_data(apellido)].list, nombre, apellido);
			menu = 0;
		}

		//Buscar Cliente
		else if (menu == 4){
			printf("\e[1;1H\e[2J");
			printf("Buscar cliente\n");
			printf("===================\n");
			printf("1) Buscar por ID\n");
			printf("2) Buscar por nombre\n");
			printf("3) Buscar por apellido\n");
			printf("Seleccione método de búsqueda: ");
			scanf("%d", &submenu);
			if (submenu == 1){
				int searchId;
				printf("===================\n");
				printf("ID: ");
				scanf("%d", &searchId);
				buscar_por_id(hash, searchId);
				menu = 0;
			}
			else if (submenu == 2){
				char* searchNombre = malloc(sizeof(char*));
				printf("===================\n");
				printf("Nombre: ");
				scanf("%s", searchNombre);
				buscar_por_nombre(hash, searchNombre);
			}
			else if (submenu == 3){
				char* searchApellido = malloc(sizeof(char*));
				printf("===================\n");
				printf("Apellido: ");
				scanf("%s", searchApellido);
				printf("Buscando %s\n", searchApellido);
				buscar_por_apellido(hash, searchApellido);
			}
			else {
				menu = 4;
			}
			menu = 0;
			submenu = 0;
		}

		//Agregar Transacción
		else if (menu == 5){
			int userId;
			int accion;
			int monto;
			Pile*edit = malloc(sizeof(Pile));
			printf("\e[1;1H\e[2J");
			printf("Agregar transacción\n");
			printf("===================\n");
			printf("ID del usuario: ");
			scanf("%d", &userId);
			printf("¿Depósito o giro? (101 para depósito, 201 para giro): ");
			scanf("%d", &accion);
			printf("Monto: ");
			scanf("%d", &monto);
			List* nodo = malloc(sizeof(List));
			for (int i = 0; i <27; i++){
				nodo = hash[i].list;
				while(nodo != NULL){
					if(nodo->id == userId){
						printf("Usuario encontrado: %s %s\n", nodo->nombre, nodo->apellido);
						ultima_transaccion = nodo->id;
						if (accion == 101){
							nodo->saldo = nodo->saldo + monto;
							agregar_elemento_pila(&nodo->transacciones, monto, accion);
						}
						else if(accion == 201){
							if (nodo->saldo - monto < 0){
								printf("No se puede realizar giro. Fondos Insuficientes.\n");
								sleep(3);
							}
							else {
								nodo->saldo = nodo->saldo - monto;
								agregar_elemento_pila(&nodo->transacciones, monto, accion);
							}
						}
					}
					nodo = nodo->next;
				}
			}
			menu = 0;
		}

		//Deshacer última Transacción
		else if (menu == 6){
			printf("\e[1;1H\e[2J");
			printf("Deshacer última transacción\n");
			printf("===================\n");
			List* nodo = malloc(sizeof(List));
			for (int i = 0; i <27; i++){
				nodo = hash[i].list;
				while(nodo != NULL){
					if(nodo->id == ultima_transaccion){
						printf("Usuario encontrado: %s %s\n", nodo->nombre, nodo->apellido);
						if (nodo->transacciones->codigo == 101){
							printf("Restando $%i al saldo\n", nodo->transacciones->monto);
							nodo->saldo = nodo->saldo - nodo->transacciones->monto;
						}
						else {
							printf("Agregando $%i al saldo\n", nodo->transacciones->monto);
							nodo->saldo = nodo->saldo + nodo->transacciones->monto;
						}
						remover_elemento_pila(&nodo->transacciones);
					}
				nodo = nodo->next;
				}
			}
			menu = 0;
		}

		//Generar lista de cilentes por última transacción TODO
		else if (menu == 7){
			printf("\e[1;1H\e[2J");
			printf("Listar clientes con transacciones recientes\n");
			printf("===================\n");
			printf("No funciona :(\n");
			sleep(3);
		}

		//Generar lista de cilentes por dinero TODO
		else if (menu == 8){
			printf("\e[1;1H\e[2J");
			printf("Listar clientes ordenados por dinero\n");
			printf("===================\n");
			printf("No funciona :(\n");
			sleep(3);
		}

		//Salir
		else if (menu == 9){
			printf("\e[1;1H\e[2J");
			printf("Listar clientes ordenados por dinero\n");
			printf("===================\n");
			printf("No funciona :(\n");
			sleep(3);
		}

		else if (menu == 50){
			printf("\e[1;1H\e[2J");
			printf("DEBUG! Listar clientes\n");
			printf("===================\n");
			listar_lista(&hash[hash_data("Perez")].list);
			sleep(4);
			menu = 0;
			sleep(1);
		}

		else if (menu == 51){
			printf("\e[1;1H\e[2J");
			printf("HASH Name\n");
			printf("===================\n");
			printf("%i\n",hash_data("Name"));
			menu = 0;
			sleep(1);
			
		}
	};
	return 0;
}

void cargar_archivo(char *filename, Hash* hash){
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
			agregar_elemento_lista(&hash[hash_data(apellido)].list, free_id, nombre, apellido, email, genero, direccion);
			free_id++;
		}
	}
	else{
		printf("\nERROR: El archivo no existe\n");
		loaded = 0;
		sleep(1);
	}
}


