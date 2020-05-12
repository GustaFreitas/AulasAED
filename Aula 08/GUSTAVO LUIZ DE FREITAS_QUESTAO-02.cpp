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

// Todas as funções tilizadas
void Cursor (int x, int y);
void Distribuidos (int x);
void Pilha_Ingressos (stack <int> Pilha);
void Mostra_Fila (queue <int> Fila);
void Ingressos (int x);

struct Pessoas // Contém todas as informações coletadas das pessoas da fila idênpendente do tipo de variável.
{
	int  Filme, Cel;
	char Nome [30], Email [60];
};

int main() // Código principal.
{
	setlocale (LC_ALL, "Portuguese");
	
	system("color 06");  // Altera a cor do cmd
	
	stack <int> Pilha;
	stack <int> Pilha_Temp;
	
	queue <int> Fila;
	
	struct Pessoas P[100];
	
	int  Filme[100], Loop = 7, Menu, Valor, x = 0 , y = 0, z = 0;
	char Resp, Resp_2;
	
	//Aleatoriza os ingresos a serem distribuidos.
	srand (time(NULL));

	for (int i = 1; i <= 100; i++)
    {
        Filme[i] = (rand() % 5);
        
        Pilha.push (Filme[i]);
        
        Fila.push(i);
    }
    
 	while(Loop == 7)
	{
		system ("CLS");
		
		printf("\n  +----------------------------------+");
    	printf("\n  | <      Cinema Algorítmico      > |");
    	printf("\n  |==================================|");
    	printf("\n  | 1 - Fazer Cadastro               |");
   		printf("\n  | 2 - Ingressos distribuidos       |");
   		printf("\n  | 3 - Ingressos disponíveis        |");
   		printf("\n  | 4 - Listar pessoas               |");
    	printf("\n  | 5 - Pessoas na fila com ingresso |");
		printf("\n  | 6 - Sair                         |");
		printf("\n  +----------------------------------+");
		printf("\n\nEscolha uma das opções: [ ]");
		Cursor(26,13);//Altera a posição do cursor.
		
		Pilha_Temp = Pilha;
		
    	scanf("%d",&Menu);
                
    	switch(Menu)
		{	
    		case 1:
			
				if(x <= 100)
				{
					do
					{
						x++;
						
						Resp   = 'n';
						Resp_2 = 'n';
						
						P[x].Filme = Pilha.top();
						Pilha.pop();
						
						system ("CLS");
						
						printf("\nO ingresso distribuido foi: ");
						Ingressos(P[x].Filme);
						  
						printf("\n------------------CADASTRO------------------");
						printf("\nDigite seu nome: ");
						fflush (stdin);	
						scanf("%s",&P[x].Nome);
						
						do
						{
							system ("CLS");
							
							printf("\nO ingresso distribuido foi: ");
							Ingressos(P[x].Filme);
							
							printf("\n------------------CADASTRO------------------");
							printf("\nDigite seu nome: %s\n",&P[x].Nome);
							
							printf("\nNumero do celular: \n(somente os nove digitos)");
							Cursor(20,7);
						    scanf("%d",&P[x].Cel);
							
							if (P[x].Cel < 100000000 || P[x].Cel > 999999999) // Garante que o número de telefone seja "válido"
							{
								printf ("\n\nNúmero de celular inválido...\n\n\a");
								
								system ("PAUSE");
							}
						}
						while (P[x].Cel < 100000000 || P[x].Cel > 999999999);
						
						printf("\n\nDigite o seu E-mail:");  
						fflush (stdin);										  	
						scanf("%s",&P[x].Email);
						
						if (x < 100)
						{
							printf("\nDeseja realizar um novo cadastro? (s/n) [ ]");
							Cursor(42,12);
							fflush (stdin);
							scanf("%c", &Resp);	
						}
						else
						{
							printf ("\n\nO cinema está cheio...\n\n\a");
					
							system ("PAUSE");
						}
						
						Fila.pop();
					}
					while (Resp == 's' || Resp == 'S');
				}
				else
				{
					printf ("\n\nO cinema está cheio...\n\n\a");
					
					system ("PAUSE");
				}
							   			
			break;
						            
			case 2:
				
				if (x > 0)
			    {
			    	system ("CLS");
					
					printf ("\nIngressos distribuidos:\n");
				
				    do
				    {
				    	y++;
				    	
				        printf("\n - ");
				
				        Ingressos (P[y].Filme);
				    }
				    while (y != x);
				    
				    y = 0;
				    
				    printf("\n");
				}
			    else
			    {
			          printf ("\nNão foram distribuidos os ingressos...\n\n\a");
			    }
				
			   	system ("PAUSE");
												
			break;
						
		    case 3:
				
				Pilha_Ingressos (Pilha); // Postra os ingressos ainda disponíveis
	
			break;	
			      
			case 4:
				
				Mostra_Fila (Fila); // Mostra a quantidade de pessoas na fila
			    
			break;
				
			case 5:
				
				if (x > 0)
			    {
			    	system ("CLS");
					
					printf ("\n\t%d PESSOA(S) COM INGRESSO(S)\n", x);
					printf (">>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<\n");
					
				    do // Exibe todas as pessoas que já retiraram um ingresso.
				    {
						z++;
						
						printf ("\nNome: %s", P[z].Nome);									  									  	
						printf ("\nNumero do celular: %d", P[z].Cel);				  	
						printf ("\nDigite o seu E-mail: %s", P[z].Email);
						printf ("\nFilme: ");
						
						Ingressos (P[z].Filme);
						
						printf ("\n>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<\n");
				    }
				    while (z != x);
				    
				    z = 0;
				    
				    printf("\n");
				}
			    else
			    {
			          printf ("\nNínguem ganhou ingresso ainda...\n\n\a");
			    }
				
			   	system ("PAUSE");
				
			break;
			            
			case 6:
			            	
			printf ("\nEncerrando programa...\n\a");
			            	
			return 0;
			            	
			break;
			
			default:
            	
                printf("\nOpcao inexistente...\n\n\a");
				
				system ("PAUSE"); 
        }                                
    }    
                
    return 0;
}

void Cursor(int x, int y) // Muda a posição do cursos. Apenas para estética.
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void Pilha_Ingressos (stack <int> Pilha) // Imprime a pilha de ingressos disponiveis.
{
    stack <int> Pilha_Temp;
    
    Pilha_Temp = Pilha;
				
	system ("CLS");

	printf ("\nIngressos ainda dispníveis: %d\n", Pilha_Temp.size());
	
    while (!Pilha_Temp.empty())
    {
        printf("\n- ");

        Ingressos (Pilha_Temp.top());
        
        Pilha_Temp.pop();
    }
    
    printf ("\n");
    
   	system ("PAUSE");
}

void Mostra_Fila (queue <int> Fila) // Imprime todoas ainda na fila.
{
	queue <int> Fila_Temp;
	
	Fila_Temp = Fila;
	
	printf("Pessoas na fila do cinema: %d \n",Fila_Temp.size());
	printf("\nFila >>> ");
	
	while(!Fila_Temp.empty())
	{	
		printf("%d°    ",Fila_Temp.front());
		
        Fila_Temp.pop();
    }
    
    printf("\n<<< Fim");
    
    system ("PAUSE");
}

void Ingressos (int x) //Identifica qual o filme.
{				
	if(x == 0)
    {
        printf ("Baby Driver\n");
    }
    else if(x == 1)
    {
        printf ("Big Hero\n");
    }
    else if(x == 2)
    {
        printf ("Liga da Justiça\n");
    }
    else if(x == 3)
    {
        printf ("Logan\n");
    }
    else if(x == 4)
    {
        printf ("Vingadores\n");
    }
}//FIM!


