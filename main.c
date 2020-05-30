//main.c 

#include "main.h"

int main (int argc, char **argv)
{
	cli(0);
}

void cli(int menu){
	if (menu == 0){
		printf("\e[1;1H\e[2J");
		printf("Main menu\n");
		printf("Enter option: ");
		scanf("%d", &selected);
		cli(selected);
	}
	if (menu == 1){
		printf("\e[1;1H\e[2J");
		printf("Load file\n");
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
    }
		else{
			printf("ERROR: El archivo no existe\n");
			printf("Press Any Key to Continue\n"); 
			getch();
			cli(0);
		}
	
	
}
