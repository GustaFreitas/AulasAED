#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_no no;

struct tipo_no
{
	int info;
	
	struct tipo_no *prox;
};

int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	no *lista = NULL;
	
	system ("PAUSE");

	return 0;
}
