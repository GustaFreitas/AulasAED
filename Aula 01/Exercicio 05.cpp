#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


int main () 
{	
	setlocale (LC_ALL, "Portuguese");
	
	struct ficha_de_aluno
	{
		char  nome[40];
		char  disciplina[40];
		float nota_prova1;
		float nota_prova2;	
	};
	
	struct ficha_de_aluno aluno[11];
	
	
	for (int i = 1; i <= 10; i++)
	{
		printf ("\n------------ Cadastro de aluno %d ------------\n\n", i);
		printf (" Nome do aluno ......: ");
		fflush (stdin);
	
		fgets  (aluno[i].nome, 40, stdin);
	
		printf (" Disciplina..........: ");
		fflush (stdin);
		fgets  (aluno[i].disciplina, 40, stdin);
	
		printf (" Informe a 1ª nota ..: ");
		scanf  ("%f", &aluno[i].nota_prova1);
	
		printf (" Informe a 2ª nota ..: ");
		scanf  ("%f", &aluno[i].nota_prova2);
	}
	
	system ("cls");
	
	for (int i = 1; i <= 10; i++) 
	{
		printf ("\n--------- Lendo os dados da struct %d ---------\n\n", i);
		printf (" Nome...............: %s", aluno[i].nome);
		printf (" Disciplina.........: %s", aluno[i].disciplina);
		printf (" Nota da Prova 1 ...: %.2f\n", aluno[i].nota_prova1);
		printf (" Nota da Prova 2 ...: %.2f\n", aluno[i].nota_prova2);
		
	}
	
	printf ("\n----------------------------------------------");
	
	getch();
	return 0;
}
