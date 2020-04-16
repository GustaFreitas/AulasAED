#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;

void Imprime (queue <int> Fila)
{
	printf ("\nImpressãon da fila:");
	printf ("\nINICIO: --> ");
	
	while (!Fila.empty())
	{
		printf ("%d - ", Fila.front());
		
		Fila.pop();
	}
	
	printf ("<-- FIM\n");
}

void Busca (queue <int> Fila)
{
	int Val;
	
	printf ("\nDigite um valor inteiro a ser encontrado na fila: ");
	scanf  ("%d", &Val);
	
	int Bol = 7;
	
	while (!Fila.empty())
	{
		if (Val == Fila.front())
		{
			Bol = true;
		}
		
		Fila.pop();
	}
	
	if (Bol == 7)
	{
		Bol = false;
	}
	
	if (Bol == 0)
	{
		printf ("Valor %d não encontrado...", Val);
	}
	else if (Bol == 1)
	{
		printf ("Valor %d encontrado...", Val);
	}
}

int main (void) 
{	
	setlocale (LC_ALL, "Portuguese");
	
	queue <int> Fila;
	
	for (int i = 0; i < 10; i++)
	{
		Fila.push(rand() % 100 + 1);
	}
	
	Imprime (Fila);
	
	Busca (Fila);

	getch();
}
