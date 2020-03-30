#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void calcula (int *x, int *y, int *z)
{
	*z = *x + *y;
	
	printf ("Primeiro número: %d\nSegundo número: %d\nSoma: %d", *x, *y, *z);
}

int main (void) 
{	
	setlocale (LC_ALL, "Portuguese");
	
	int Num1 = 5, Num2 = 7, Soma = 0;
	
	calcula (&Num1, &Num2, &Soma);

	getch();
	return 0;
}
