#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	queue<int> fila;
	
	fila.push (0);
	fila.push (1);
	fila.push (2);
	fila.push (3);
	fila.push (4);
	fila.push (5);
	fila.push (6);
	fila.push (7);
	fila.push (8);
	fila.push (9);
	
	
	printf ("Tamanho da fila: %d \n", fila.size());
	
	printf ("Primeiro elemento da fila: %d \n", fila.front());
	
	fila.pop();
	
	printf ("O primeiro elemento da fila AGORA: %d \n", fila.front());
	
	printf ("Tamanho da fila: %d \n", fila.size());
}
