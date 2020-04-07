#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

void Imp_Pil (stack <int> Pilha)
{
	printf ("Pilha: \n\n");
	
	while (!Pilha.empty())
	{
		printf ("%d \n", Pilha.top());
		
		Pilha.pop();
	}
	printf ("\n");
}

void Pes_Pil (stack <int> Pilha)
{
	int Num, i = 0;
	
	scanf ("%d", &Num);
	
	system ("CLS");
	
	while (!Pilha.empty())
	{
		i++;
		
		if (Pilha.top() != Num)
		{
			printf ("Valor %d excu�do do topo da pilha...\n", Pilha.top());
			Pilha.pop();
		}
		else if (Pilha.top() == Num)
		{
			printf ("\nN�mero %d encontrado na posi��o %d.\nTodos os n�meros acima dele foram exclu�dos.\n\n", Pilha.top(), i);
			
			getch();
			
			system ("CLS");
			
			printf ("Nova pilha com %d elementos:\n\n", Pilha.size());
			
			Imp_Pil (Pilha);
			
			break;
		}
	}
	if (Pilha.empty())
	{
		printf ("\nN�mero n�o encontrado!\n\n");
	}
}

void Som_Pil (stack <int> Pilha)
{
	int Aux = 0;
	
	while (!Pilha.empty())
	{
		Aux = Aux +Pilha.top();
		Pilha.pop();
	}
	
	printf ("A soma de TODOS os n�meros da pilha �: %d\n", Aux);
}

int main (void) 
{	
	setlocale (LC_ALL, "Portuguese");
	
	int Num = 0;
	stack<int> Pilha;
	
	for (int i = 1; i <= 100; i++)
	{
		Pilha.push(rand() % 100 + 1);
	}
	
	Imp_Pil (Pilha);
	
	printf ("Qual n�mero voc� deseja encontrar? ");
	Pes_Pil (Pilha);
	
	Som_Pil (Pilha);
	
	return 0;
}
