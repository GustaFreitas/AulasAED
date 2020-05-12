//O código podia ter ficado mais enxuto com uso de ponteiros, mas me falta conhecimento na área.

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
void Cursor(int x, int y);
int Codigo_Cliente (queue <int> Fila, int Cod);
void Imprime_Cardapio ();
int  Buscar (queue <int> Fila, int x);
void Pilha_Chocolates (stack <int> Pilha, char Por);
void Sabores_Chocolates (int x, char por);

struct Cliente // Contém todas as informações coletadas do cliente idênpendente do tipo de variável.
{
	char   Nome[30];
	int    Cod, Pedi, Qtd_1 = 0, Qtd_2 = 0, Qtd_3 = 0, Qtd_4 = 0, Qtd_5 = 0, Qtd_Tot = 0;
	float  Tot_Pag = 0, Tot_1 = 0, Tot_2 = 0, Tot_3 = 0, Tot_4 = 0, Tot_5 = 0;
};

int main() // Código principal.
{
	setlocale (LC_ALL, "Portuguese");
	
 	struct Cliente C[10];
 	
 	stack <int> Pilha;
 	stack <int> Pilha_Temp;
 	
 	queue <int> Fila;
 	queue <int> Fila_Temp;
	
	int  Cod, Choc[10], Loop = 7, Menu, Qtd, x = 0, y = 0, z = 0;
	char Resp, Por = '%';
	
	// Aleatoriza o sabor dos chocolates distribuidos.
	srand (time(NULL));
	
    for (int i = 1; i <= 10; i++)
    {
    	Choc[i] = (rand() % 5);
    	
    	Pilha.push (Choc[i]);
    }
  
 	while(Loop == 7) //Loop infinito até que seja digitado o valor 4.
	{
		system ("CLS");
		
		system("color 02"); // Altera a cor do cmd
		
		printf("\n  +------------------------------+");
    	printf("\n  | < Restaurante  Algorítmico > |");
    	printf("\n  |==============================|");
    	printf("\n  | 1 - Adicionar novo cliente   |");
		printf("\n  | 2 - Buscar cliente           |");
   		printf("\n  | 3 - Fila de clientes         |");
    	printf("\n  | 4 - Receber chocolates       |");
		printf("\n  | 5 - Sair                     |");
		printf("\n  +------------------------------+");
		printf("\n\nEscolha uma das opções: [ ]");
		Cursor(26,12); // Altera a posição do cursor.
		
    	scanf("%d",&Menu);
                
    	switch(Menu)
		{	
    		case 1:
    			
    			do
				{
					x++;
					Resp  = 'n';
					
					if (x <= 10)
    				{	
						do
						{
						
							Resp  = 'n';
							
							do
							{						
								Imprime_Cardapio();
								
								printf("Digite o código de qual produto deseja: [ ]");
								Cursor(42,42);
								scanf ("%d",&C[x].Pedi);
								
								if (C[x].Pedi <= 0 || C[x].Pedi >= 11)
								{
									printf("\n\n#ERROR - Código do pedido errado... \n\n\a");
									
									system ("PAUSE");
								}
							} 
							while (C[x].Pedi <= 0 || C[x].Pedi >= 11);
							
							printf("\nDigite a quantidade: [  ]");
							Cursor(23,44);
							scanf ("%d",&Qtd);
							   				
							switch(C[x].Pedi) // Calcula todos os valores de acordo com o código do produto.
							{
								case 1:
									
									C[x].Qtd_1 = C[x].Qtd_1 + Qtd;
									C[x].Qtd_Tot = C[x].Qtd_Tot + Qtd;
									C[x].Tot_1 = C[x].Tot_1 + (14.99 * Qtd);
									C[x].Tot_Pag = C[x].Tot_Pag + C[x].Tot_1; 
										
								break;
											
								case 2:  
								
							   		C[x].Qtd_2 = C[x].Qtd_2 + Qtd;
							   		C[x].Qtd_Tot = C[x].Qtd_Tot + Qtd;
									C[x].Tot_2 = C[x].Tot_2 + (Qtd * 17.9);
									C[x].Tot_Pag = C[x].Tot_Pag + C[x].Tot_2; 
							   		
								break;
											
								case 3:
									
									C[x].Qtd_3 = C[x].Qtd_3 + Qtd;
									C[x].Qtd_Tot = C[x].Qtd_Tot + Qtd;
									C[x].Tot_3 = C[x].Tot_3 + (Qtd * 4.99);
									C[x].Tot_Pag = C[x].Tot_Pag + C[x].Tot_3; 
											
								break;
								
								case 4:
									
									C[x].Qtd_4 = C[x].Qtd_4 + Qtd;
									C[x].Qtd_Tot = C[x].Qtd_Tot + Qtd;
									C[x].Tot_4 = C[x].Tot_4 + (Qtd * 5.5);
									C[x].Tot_Pag = C[x].Tot_Pag + C[x].Tot_4; 
										
								break;
								
								case 5:
									
									C[x].Qtd_5 = C[x].Qtd_5 + Qtd;
									C[x].Qtd_Tot = C[x].Qtd_Tot + Qtd;
									C[x].Tot_5 = C[x].Tot_5 + (Qtd * 2.5);
									C[x].Tot_Pag = C[x].Tot_Pag + C[x].Tot_5; 
										
								break;			
							}
							
							printf("\nDeseja realizar um novo pedido? (s/n) [ ]");
							Cursor(40,46);
							fflush (stdin);
							scanf("%c", &Resp);
						}
						while (Resp == 's' || Resp == 'S');
						
						Resp  = 'n';
						y++;
										   				   			
						printf("\nDigite o nome do cliente: [ ]");
						Cursor(28,48);		
						fflush (stdin);									    
						scanf("%s",&C[x].Nome);
						
						// Aleatoriaza um código para cada cliente.
						Cod = (rand() % 100);
    	
				    	Cod = Codigo_Cliente (Fila, Cod);
				    	
				    	Fila.push (Cod);
	
						if (x <= 10
						)
						{
							printf("\nDeseja realizar um novo cadastro? (s/n) [ ]");
							Cursor(42,50);
							fflush (stdin);	
							scanf("%c", &Resp);
						}
						else
						{
							printf ("\nFila cheia!!!\n\n\a");
							
							system ("PAUSE");
						}
						
					}
					else
					{
						printf ("\nFila cheia!!!\n\n\a");
						
						system ("PAUSE");
					}
				
				}
					while (Resp == 's' || Resp == 'S');					
            break;
            
            case 2:
            	
            	printf("\nInforme o valor a ser pesquisado na fila: [ ]");
            	Cursor(44,14);
				scanf("%d",&y);
            	
            	z = Buscar (Fila, y);
            	
            	if (z > 0)
            	{
                	printf("\n\nNome do cliente: %s", C[z].Nome);
					printf("\n=================================================");
					printf("\n  PRODUTO       -------  QTD  ------- Total(R$)");
					printf("\n=================================================");
					printf("\n  Prato Feito   _______   %d   _______  R$%.2f", C[z].Qtd_1, C[z].Tot_1);
					printf("\n  Macarronada   _______   %d   _______  R$%.2f", C[z].Qtd_2, C[z].Tot_2);
					printf("\n  Salgados      _______   %d   _______  R$%.2f", C[z].Qtd_3, C[z].Tot_3);
					printf("\n  Sucos         _______   %d   _______  R$%.2f", C[z].Qtd_4, C[z].Tot_4);
					printf("\n  Doces         _______   %d   _______  R$%.2f", C[z].Qtd_5, C[z].Tot_5);
					printf("\n=================================================");
					printf("\n  TOTAL                   %d            R$%.2f", C[z].Qtd_Tot, C[z].Tot_Pag);
					printf("\n=================================================\n\n");
					
					system ("PAUSE");
				}
            	
            break;
            
            case 3:
            	if (x > 0)
            	{
					system ("CLS");
	            	
					y = 1;
	                
				    Fila_Temp = Fila; // Busca um cliente dentro da fila e exibe a comanda indivdualmente.
					
				    printf("Pessoas na fila do caixa: %d \n",Fila_Temp.size());
				    printf("\nFila >>> ");
				    
				    while(!Fila_Temp.empty())
					{	
						printf("%s  Nº%d  ||  ",C[y].Nome, Fila_Temp.front());
						
				        Fila_Temp.pop();
				        
				        y++;
				    }
				    
	                printf ("\n\n");
	                
	                y = x;
	                
	               	for (int j = 1;j <= 5; j++)
	    			{
	    				
		                	printf("Nome do cliente: %s", C[j].Nome);
							printf("\n=================================================");
							printf("\n  PRODUTO       -------  QTD  ------- Total(R$)");
							printf("\n=================================================");
							printf("\n  Prato Feito   _______   %d   _______  R$%.2f", C[j].Qtd_1, C[j].Tot_1);
							printf("\n  Macarronada   _______   %d   _______  R$%.2f", C[j].Qtd_2, C[j].Tot_2);
							printf("\n  Salgados      _______   %d   _______  R$%.2f", C[j].Qtd_3, C[j].Tot_3);
							printf("\n  Sucos         _______   %d   _______  R$%.2f", C[j].Qtd_4, C[j].Tot_4);
							printf("\n  Doces         _______   %d   _______  R$%.2f", C[j].Qtd_5, C[j].Tot_5);
							printf("\n=================================================");
							printf("\n  TOTAL                   %d            R$%.2f", C[j].Qtd_Tot, C[j].Tot_Pag);
							printf("\n=================================================\n\n");
							
						
	    			}
					
					system ("PAUSE");	
				}
				else
				{
					printf ("\nFila vazia...\n\n");
					
					system ("PAUSE");
				}
				
            break;
            
			case 4:
				
				system ("CLS");
				
				printf ("\nChocolates disponiveis na pilha:\n");
				
				Pilha_Chocolates (Pilha, Por); // Imprime todos os chocolates da pilha.
				
				printf ("\n======================================\n");
				
			    Pilha_Temp = Pilha;
					
				if (y > 0)
				{
					printf ("\nChocolates distribuidos:\n");
					
					z = 1;
					
					while (!Pilha_Temp.empty() && y > 0) // Define qual chocolate vai ser direcionado para cada cliente.
					{
						printf ("\n- %s recebeu um c", C[z].Nome);
						
						Sabores_Chocolates (Pilha_Temp.top(), Por);
						
						printf (".\n");
						
						Pilha_Temp.pop();
						
						z++;
						y--;
	      			}
	      			
	      			y = x;
	      			z = 0;
				}
				else
				{
	      			printf ("\nNão foram distribuidos chocolates.\n\n");
				}
				
				printf ("\n");
				
				system ("PAUSE");
      			
            break;
            
            case 5:
            	
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

int Codigo_Cliente (queue <int> Fila, int Cod)// Verifica se o código do cliente já existe. Caso exista um novo código é gerado.
{
	queue <int> Fila_Temp;
	
	Fila_Temp = Fila;
	
	dnovo:
	
	while (!Fila_Temp.empty())
	{
		if (Cod == Fila_Temp.front() || Cod == 0)
		{
			Cod = (rand() % 100);

			goto dnovo;
		}
		
		Fila_Temp.pop();
	}
	
	return Cod;
}

void Imprime_Cardapio () 
{
	system ("CLS");
									  
	printf("\n|| ============== CARDÁPIO ============== ||\n");
	printf("\n  (1) Prato Feito  -------------- R$ 14,99");
	printf("\n   Descrição ...  Arroz\n\t\t  Feijão\n\t\t  Batata frita\n\t\t  Bife (bovino ou frango)\n\t\t  Salada\n");									  									  			  	
	printf("\n  (2) Macarronada  -------------- R$ 17,90");
	printf("\n   Descrição ...  Macarrão a bolonhesa\n\t\t  Acompanhamentos:\n\t\t  Ovos de codorna\n\t\t  Mussarela\n\t\t  Calabresa\n\t\t  Bacon\n\t\t  Frango\n\t\t  Milho\n\t\t  Brócolis\n");
	printf("\n  (3) Salgados  ------------------ R$ 4,99");
	printf("\n   Descrição ...  Coxinha\n\t\t  Kibe\n\t\t  Empada\n\t\t  Pastel(queijo e carne)\n");
	printf("\n  (4) Suco Natural  ------------  R$ 05,50");
	printf("\n   Descrição ...  Laranja\n\t\t  Limão\n\t\t  Goiaba\n\t\t  Uva\n");
	printf("\n  (5) Doces  -------------------  R$ 02,00");
	printf("\n   Descrição ...  Brigadeiro\n\t\t  Prestigio\n\t\t  Beijinho\n\t\t  Pé de moleque\n");	
	printf("\n|| ====================================== ||\n\n");
}

int Buscar (queue <int> Fila, int x)// Mecanismo de busca de cliente.
{
	queue <int> Fila_Temp;
	
	Fila_Temp = Fila;
	
	int i = 0;
	
	while(!Fila_Temp.empty())
	{
		i++;
		
		if (Fila_Temp.front() == x)
		{
			printf("\nValor %d encontrado na %d posição da fila.\n\n", x, i);
			
			system ("PAUSE");

			return i;
		}
		
		Fila_Temp.pop();
		
	}
	
    printf("\nValor %d  NÃO encontrado na fila...\n\n\a", x);
    
    system ("PAUSE");
    
    return 0;
}

void Pilha_Chocolates (stack <int> Pilha, char Por) //Imprime a pilha dos chocolates.
{
    stack <int> Pilha_Temp;
    
    Pilha_Temp = Pilha;
	
    while (!Pilha_Temp.empty())
    { 
        printf("\n- C");
						
		Sabores_Chocolates (Pilha_Temp.top(), Por);
			
		printf(" -\n");
		
		Pilha_Temp.pop();
    }
}

void Sabores_Chocolates (int x, char por) //Imprime o sabor dos chocolates.
{				
	if (x == 0)
	{
		printf ("hocolate ao leite");
	}		
	else if (x == 1)
	{
	   	printf ("hocolate branco");
	}
	else if (x == 2)
	{
		printf ("hocolate com avelã");
	}
	else if (x == 3)
	{
		printf ("hocolate 70%c cacau", por);
	}
	else if (x == 4)
	{
		printf ("hocolate zero lactose");
	}
}//FIM!!!
