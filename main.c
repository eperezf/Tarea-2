//main.c 

#include "main.h"

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
		printf("===================\n");
		if (strcmp(&filename, "")!=0){
			printf("Archivo abierto: %s\n", &filename);
		}
		printf("Enter option: ");
		scanf("%d", &selected);
		cli(selected);
	}
	if (menu == 1){
		printf("\e[1;1H\e[2J");
		printf("Abrir archivo de clientes\n");
		printf("===================\n");
		printf("Escriba la ruta del archivo: ");
		scanf("%s", &filename);
		leer_archivo(&filename);
	}
	
}

void leer_archivo(const char * filename){
	char line[255];
	int linelength;
	FILE *fp;
	if ((fp = fopen(filename, "r"))){
		fp = fopen(filename, "r");
		printf("Archivo abierto correctamente. Guardando en memoria...\n");
		cli(0);
    }
		else{
			printf("\nERROR: El archivo no existe\n");
			strcpy(filename, 'null');
			sleep(1);
			cli(0);
		}
	
	
}
