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
		leer_archivo(&filename);
	}
	if (menu == 2){
		printf("\e[1;1H\e[2J");
		printf("Agregar cliente\n");
		printf("===================\n");
	}
	
}

void leer_archivo(const char * filename){
	char line[255];
	int linelength;
	FILE *fp;
	if ((fp = fopen(filename, "r"))){
		fp = fopen(filename, "r");
		printf("Archivo abierto correctamente. Guardando en memoria...\n");
		loaded = 1;
		fgets(line, 255, fp);
		printf("%s", line);
		int id;
		char* nombre;
    char* apellido;
    char* email;
    char* genero;
    char* direccion;
    char aux[1000];
		fgets(aux,999,fp);
		id = atoi(strtok(aux,"\t"));
    nombre = strtok(NULL,"\t");
    apellido = strtok(NULL,"\t");
    email = strtok(NULL,"\t");
		genero = strtok(NULL,"\t");
		direccion = strtok(NULL, "\n");
	

		printf("ID: %i\n", id);
		printf("NOMBRE: %s\n", nombre);
		printf("APELLIDO: %s\n", apellido);
		printf("EMAIL: %s\n", email);
		printf("GENERO: %s\n", genero);
		printf("DIRECCIÓN: %s\n", direccion);
		sleep(5);
		cli(0);
  }
	else{
		printf("\nERROR: El archivo no existe\n");
		loaded = 0;
		sleep(1);
		cli(0);
	}

}
