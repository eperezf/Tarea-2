#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cli(int menu);

void leer_archivo(const char * filename);
int selected;
char filename;
int loaded;