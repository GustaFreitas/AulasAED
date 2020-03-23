#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct Bolsa
{
	char  Nom[50], Are[20];
	float Val_Atu, Val_Ant, Dif;
	double Var;
};

float Media (float x)
{
	return	(x / 5);
}

float Novo (float x, float y)
{
	return	(x + y);
}



int main (void) 
{	
	setlocale (LC_ALL, "Portuguese");
	
	struct Bolsa V[6];
	
	char Aux = '%';
	
	for (int i = 1; i <= 5; i++)
	{
	
		printf ("Informe o nome da compania: ");
		scanf  ("%s", &V[i].Nom);
		fflush (stdin);
	
		printf ("Informe a área de atuação da compania: ");
		scanf  ("%s", &V[i].Are);
		fflush (stdin);
	
		printf ("Informe o valor atual das ações: ");
		scanf  ("%f", &V[i].Val_Atu);
		fflush (stdin);
	
		printf ("Informe o valor anterior das ações: ");
		scanf  ("%f", &V[i].Val_Ant);
		fflush (stdin);
	
		V[i].Dif = V[i].Val_Atu - V[i].Val_Ant;
	
		V[i].Var = (V[i].Dif * 100) / V[i].Val_Ant;
		
		if (V[i].Dif < 0)
		{
			printf ("A compania %s do ramo de %s teve uma queda de %.2lf%c desde a abertura da bolsa.\n", V[i].Nom, V[i].Are, V[i].Var, Aux);
   		}
    	else
    	{
    		printf ("\n\n A compania %s do ramo de %s teve um aumento de %.2lf%C desde a abertura da bolsa.\n", V[i].Nom, V[i].Are, V[i].Var, Aux);
		}
		
		printf ("----------------------------------------------------------------------------------\n");
	}
	
	system ("pause");
	system ("cls");
	
	float Val, Med, Par;
	
	printf ("Informe um valor de ação: ");
	scanf  ("%f", &Val);
	
	printf ("As seguintes ações estão do indicado:\n");
	
	for (int i = 1; i <= 5; i++)
	{
		if (Val > V[i].Val_Atu)
		{
			printf ("Compania: %s\n", V[i].Nom);
			printf ("Valor das ações: %.2f\n\n", V[i].Val_Atu);
		}
		
		Med = Med + V[i].Val_Atu;
	}
	
	system ("pause");
	system ("cls");
	
	printf ("A média das ações é: %.2f\n\n", Media (Med));
	
	system ("pause");
	system ("cls");
	
	printf ("Escolha um novo parametro para alterar as acões de todas as companias: ");
	scanf  ("%f", &Par);
	
	("----------------------------------------------------------------------------------\n\n");
	
	for (int i = 1; i <= 5; i++)
	{
		V[i].Val_Atu = Novo (Par, V[i].Val_Atu);
		
		V[i].Dif = V[i].Val_Atu - V[i].Val_Ant;
	
		V[i].Var = (V[i].Dif * 100) / V[i].Val_Ant;
		
		printf ("Compania: %s\n", V[i].Nom);
		printf ("Novo valor de ações: %.2f\n", V[i].Val_Atu);
		
		
		if (V[i].Dif < 0)
		{
			printf ("A compania %s do ramo de %s teve uma queda de %.2lf%c desde a abertura da bolsa.\n", V[i].Nom, V[i].Are, V[i].Var, Aux);
   		}
    	else
    	{
    		printf ("\n\n A compania %s do ramo de %s teve um aumento de %.2lf%C desde a abertura da bolsa.\n", V[i].Nom, V[i].Are, V[i].Var, Aux);
		}
		
		printf ("----------------------------------------------------------------------------------\n");
	}

	getch();
	return 0;
}
