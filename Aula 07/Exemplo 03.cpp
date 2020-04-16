#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

void imprime (queue <int> fila)
{
	printf ("\nImpressãon da fila:");
	printf ("\nINICIO? -->");
	
	while (!fila.empty())
	{
		printf ("%d - ", fila.front());
		
		fila.pop();
	}
	
	printf ("<-- FIM\n");
}

int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	queue<int> fila;
	
	for (int i = 0; i < 10; i++)
	{
		fila.push(i);
	}
	
	printf ("INFIRMAÇÕES DA FILA:\n");
	printf ("Tamanho da fila: %d \n", fila.size());
	printf ("Primeiro elemento da fila: %d \n", fila.front());
	printf ("Último elemento da fila: %d \n", fila.back());
	
	printf ("\n\n");
	
	imprime (fila);
	
	printf ("Retirando elemenro da fila. pop()\n");
	imprime (fila);
	
	
	printf ("\nAdicionando valor 50 na fila. pish()\n");
	fila.push(50);
	
	imprime (fila);

	return 0;
}
