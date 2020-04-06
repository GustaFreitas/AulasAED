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

void insereInicio (int n, no **inicio);

int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	no *lista = NULL;
	
	insereInicio (3, &lista);
	insereInicio (2, &lista);
	insereInicio (1, &lista);

	return 0;
}

void insereInicio (int n, no **inicio)
{
	no *aux = (no*) malloc(sizeof(no));
	
	if (aux)
	{
		aux -> info = n;
		
		if (!(*inicio))
		{
			*inicio = aux;
			
			(*inicio)->prox = NULL;
		}
		else
		{
			aux -> prox = *inicio;
		
			*inicio = aux; 
		}
	}
	else
	{
		printf ("Heap cheio!\n");
	}
	
	return;
}
