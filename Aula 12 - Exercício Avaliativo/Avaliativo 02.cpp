#include <conio.h>
#include <iostream>
#include <locale.h>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

using namespace std;

void Menu ();
void Cursor(int x, int y);
void Contar(queue <int> Fila);
void Decolar(queue <int> Fila);
void Adicionar(queue <int> Fila, int *num, int *mod, int *ano);
void Listar(queue<int> Fila);
void Detalhar();
int Validar(queue <int> Fila);
int Numerar (queue <int> Fila);

int main (void) 
{	
	setlocale (LC_ALL, "Portuguese");
		
	system("color 02");
	
	int x = 0;
	int aux;
	int opc;
	char Resp;
	
	struct carac_Aviao
	{
		int   num;
		char  mod[10];
		int   ano;
	};
	
	struct carac_Aviao c[100];
	
	queue<int> Fila;
	
	do{
		x++;
		
		Menu();
		scanf("%d",&opc);
	   	
		switch (opc){
			case 1:
				Contar(Fila);
				
				break;
			case 2:
				Decolar(Fila);
				
				Fila.pop();
				
				break;
			case 3:
				c[x].num = Numerar (Fila);
				
				printf("\nQual o modelo do avi�o?");
				scanf ("%s",&c[x].mod);
				
				printf("\nQual o ano do avi�o?");
				scanf ("%d",&c[x].ano);
				
				Fila.push (c[x].num);
				
				break;
			case 4:
				Listar(Fila);
				
				break;
			case 5:
				int val;
	
				val = Validar(Fila);
				
				if (val == 1){
					
					while (!Fila.empty()){
						
						if(Fila.front() == c[x].num){
							printf ("Pr�ximo avi�o a decolar:");
							printf ("\n\nNumero: %d", c[x].num);
							printf ("\nModelo: %s", c[x].mod);
							printf ("\nAno: %d", c[x].ano);
							
							system ("PAUSE");
						}
					}	
				}
				
				break;
			case 6:
				printf ("\nEncerrando programa...\n\a");
	            	
	            return 0;
				
				break;
				
			default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                system("pause");
		}
		printf("\nDeseja realizar um novo pedido? (s/n) [");
		fflush (stdin);
		scanf("%c", &Resp);
		
	} while (Resp == 's' || Resp == 'S');
	

	getch();
	return 0;
}

void Cursor(int x, int y){

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void Menu (){
	
	system ("CLS");
	
	printf("\n  +-------------------------------------+");
	printf("\n  | <         AEROPORTO XIV BIS       > |");
	printf("\n  |=====================================|");
	printf("\n  | 1 - Quantidade de avi�es em espera  |");
	printf("\n  | 2 - Autorizar decolagem             |");
	printf("\n  | 3 - Adicionar avi�o a fila          |");
	printf("\n  | 4 - Avi�es aguardando para decolar  |");
	printf("\n  | 5 - Detalhes do pr�ximo v�o         |");
	printf("\n  | 6 - Encerrar programa               |");
	printf("\n  +-------------------------------------+");
	printf("\n\nEscolha uma das op��es: [ ]");
	Cursor(26,13);
}

void Contar(queue <int> Fila){
	
	int val;
	
	val = Validar(Fila);
	
	if (val == 1){
		
		printf("A quantidade de avi�es esperando para decolar � de %d.\n",Fila.size());
	}
}

void Decolar(queue <int> Fila){
	
	char val;
	
	val = Validar(Fila);
	
	if (val == 1){
	
	printf ("Avi�o %d autorizado a decolar.",Fila.front());
	
	}
}

void Adicionar(queue <int> Fila, int num, int mod, int ano){
	
	num = Numerar (Fila);
	char aux;
	int aux2;
	
	printf("\nQual o modelo do avi�o?");
	scanf ("%s",&aux);
	
	printf("\nQual o ano do avi�o?");
	scanf ("%d",&aux2);
	
	mod = aux;
	ano = aux2;
	
	Fila.push (num);
}

void Listar(queue<int> Fila){
	
	int y = 1;
	
	queue<int> Fila_Temp;
	               
    Fila_Temp = Fila; 
	
    printf("Avi�es na fila para decolar:\n");
    
    while(!Fila_Temp.empty())
	{	
		printf("N� %d  ||  ", Fila_Temp.front());
		
        Fila_Temp.pop();
        
        y++;
    }
}

void Detalhar(){
	
}

int Validar(queue <int> Fila){
	
	if (Fila.empty()){
		
		printf("\nFila vazia!\n\n");
		
		system ("PAUSE");
		
		return 0;
		
	} else {
		
		return 1;
	}
}

int Numerar (queue <int> Fila)
{
	int num = (rand() % 9999);
	
	queue <int> Fila_Temp;
	
	Fila_Temp = Fila;
	
	dnovo:
	
	while (!Fila_Temp.empty())
	{
		if (num == Fila_Temp.front() || num == 0)
		{
			num = (rand() % 9999);

			goto dnovo;
		}
		
		Fila_Temp.pop();
	}
	
	return num;
}
