#include <conio.h>
#include <iostream>
#include <locale.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
// Bibliotecas exclusicas para o calcuro de temperatura.
#define ZEROABSC -273.15
#define ZEROABSF -459.67

// Todas as fun��es tilizadas
void Cursor(int x, int y);
void Menu();
float Temperatura (int opcao);
float Converte_Temperatura(int opcao, float *Temp);

int main(void) // C�digo principal.
{
	setlocale (LC_ALL, "Portuguese");
	
	system("color f5");  // Altera a cor do cmd
	
	float Temp, Conv;
	int Opc;

 	do
	{
		Menu();
		Cursor(10,6);//Altera a posi��o do cursor.
		scanf("%d", &Opc);
		
 		switch(Opc)
		{
	 		case 1:
	 			
				 Temp = Temperatura(Opc);
				 Conv = Converte_Temperatura(Opc, &Temp);
				 
				 printf("\n%.2f C s�o %.2f F.\n\n", Temp, Conv);
				 
				 system ("PAUSE");
				 
		 	break;
	 	 
		 	case 2:
		 		
				Temp = Temperatura(Opc);
			    Conv = Converte_Temperatura(Opc, &Temp);
			    
			    printf("\n%.2f F s�o %.2f C.\n\n", Temp, Conv);
			    
			    system ("PAUSE");
			    
			break;
			 
			case 3:
				
				printf("\nSaindo...\a");
				
			break;
		
	  		default:
			  
			  printf("Valor inv�lido...\n");
		}
	}
	while(Opc != 3);
	
	return 0;
}

void Cursor(int x, int y) // Muda a posi��o do cursos. Apenas para est�tica.
{
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void Menu()
{
	system ("CLS");
		
	printf(" \n============MENU============\n");
	printf(" 1 - Celsius para Fahreinheit\n");
	printf(" 2 - Fahreinheit para Celsius\n");
	printf(" 3 - Sair.\n");
	printf(" Opcao: [ ]");
}

float Temperatura(int opcao) // Valida se a temperatura � v�lida.
{
	float Temp;
	bool teste;
	
	do
	{
		printf("\nDigite a Temperatura: [    ]");
		Cursor(24,8);
		scanf("%f", &Temp);
		
		if( ((opcao == 1) && (Temp < ZEROABSC)) || ((opcao == 2) && (Temp < ZEROABSF)) )
		{
			printf("\nTemperatura inv�lida. Digite novamente.\n\n");
			
			system ("PAUSE");
			
			Menu();
			
			printf ("\n");
			
			teste = false;
		}
		else
		{
			teste = true;
		}
		
	}
	while(!teste);
	
	return Temp;
	
}
	
float Converte_Temperatura(int opcao, float *Temp) // converte a temperatura idep�ndente da unidade.
{
	float conversao;
	if(opcao == 1)
	{
		conversao = *Temp * 1.8 + 32;
	}
	else
	{
	conversao = (*Temp - 32) / 1.8;
	}
	
	return conversao;
}
