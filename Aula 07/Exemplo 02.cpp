#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

void imprime (queue <int> fila)
{
	while (!fila.empty())
	{
		printf ("\n%d", fila.front());
		
		fila.pop();
	}
}

int main (void) 
{	
	setlocale (LC_ALL, "Portuguese");
	
	queue <int> fila;
	
	for (int i = 0; i < 10; i++)
	{
		fila.push(i);
	}
	
	printf ("Tamanho da fila: %d \n", fila.size());
	printf ("Primeiro elemento da fila: %d \n", fila.front());
	fila.pop();
	printf ("O primeiro elemento da fila AGORA: %d \n", fila.front());
	printf ("Tamanho da fila: %d \n", fila.size());
	
	imprime (fila);


}
