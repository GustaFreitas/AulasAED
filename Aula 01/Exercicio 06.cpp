#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

float calcula (float x, float y)
{
	return	(x+y);
}

int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	struct Numeros
	{
		float N;
	};
	
	struct Numeros Num[5];
	
	for (int i = 1; i <= 4; i++)
	{
		fflush (stdin);
		printf (" Informe o %dº número: ", i);
		scanf  ("%f", &Num[i].N);
	}
	
	float Res = 0, Tot = 0;
	
	system ("cls");
	
	printf ("Resoltados:\n\n");
	
	for (int i = 1; i <= 4; i++)
	{
		Tot = calcula (Res, Num[i].N);
		
		printf ("Resultado de %.2f + %.2f = %.2f\n", Res, Num[i].N, Tot);
		
		Res = Tot;		
	}
	
	getch();
	return 0;
}
