#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

float calcula (float x, float y, float z)
{
	return	(sqrt (x+y+z));
}


int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	printf ("Resultado: %3.2f\n", calcula (2,3,4));
	printf ("\n\n");
	system ("pause");
	
	return 0;
}
