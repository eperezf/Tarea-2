#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "hash.h"


int menu;
int submenu;
int loaded;
int firstload;
int ultima_transaccion;
int free_id = 1;

void cargar_archivo(char *filename, Hash* hash);
