//Exercício incompleto. Finalizarei posteriormente.

#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;

struct Fila
{
	char	Nom_Car[50];
	float	Temp;
};

void imprime (queue <int> fila)
{
	printf ("\nImpressãon da fila:");
	printf ("\nINICIO: -->");
	
	while (!fila.empty())
	{
		printf ("%d - ", fila.front());
		
		fila.pop();
	}
	
	printf ("<-- FIM\n");
}

void informacoes (queue <int> senha)
{
	printf ("\n\tINFORMAÇÕES DA FILA:\n");
	printf ("Tamanho da fila: %d \n", senha.size());
	printf ("Primeiro elemento da fila: %d \n", senha.front());
	printf ("Último elemento da fila: %d \n", senha.back());
	printf ("\n\n");
}

void ordem (queue <int> tempo, Tem)
{
	float Men;
	
	while (!tempo.empty())
	{
		if (Tem < Men)
		{
			Men = Tem;
		}
		tempo.pop();
	}
	
	printf ("O primeiro carro a ser lavado será o com tempo de %f", Tem);
}

int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	queue <int> Senha;
	
	struct Fila F;
	
	char Opc;
	
	do
	{
		int i;
		i = i + 1;
		
		fflush (stdin);
		
		printf ("Digite o nome do cliente: ");
		scanf  ("%c", &F.Nom_Car);
		printf ("Digite o tempo gasto para lavagem: ");
		scanf  ("%f", &F.Temp);
		
		F.Tot = F.Val_Uni * F.QTD;
		
		Senha.push(i);
		
		fflush (stdin);
		printf ("Deseja adicionar um novo cliente? (s/n) -");
		scanf  ("%c", &Opc);
		
	} while (Opc == 's' || Opc == 'S');
	
	informacoes (Senha);
	
	imprime (Senha);
	
	do
	{
	fflush (stdin);
		
	printf ("Retirando elemenro da fila. pop()\n");
	imprime (Senha);
	
	printf ("Deseja adicionar um novo cliente? (s/n) -");
	scanf  ("%c", &Opc);
		
	} while (Opc == 's' || Opc == 'S');
}
