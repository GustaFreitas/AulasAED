#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{	
	setlocale (LC_ALL, "Portuguese");
	
	int x = 2, y = 3;
	int z = x + y;
	
	printf ("Os endere�os das vari�veis s�o:\n");
	printf ("x = %d\n", &x);
	printf ("y = %d\n", &y);
	printf ("z = %d\n", &z);
	printf ("\n");
	
	printf ("Os valores das vari�veis s�o:\n");
	printf ("x = %d\n", x);
	printf ("y = %d\n", y);
	printf ("z = %d\n", z);
	printf ("\n");
	
	int *px = &x;
	int *py = &y;
	int *pz = &z;
	
	printf ("Os endere�os dos ponteiros s�o:\n");
	printf ("px = %d\n", &px);
	printf ("py = %d\n", &py);
	printf ("pz = %d\n", &pz);
	printf ("\n");
	
	printf ("Os valores apontados pelos ponteiros s�o:\n");
	printf ("*px = %d\n", *px);
	printf ("*py = %d\n", *py);
	printf ("*pz = %d\n", *pz);
	printf ("\n");
	
	getch();
	return 0;
}
