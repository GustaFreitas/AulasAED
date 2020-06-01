#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <locale.h>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

using namespace std;
int main(){
	
	setlocale (LC_ALL, "Portuguese");
		
	system("color 02");
	
	int num[10000];
	int num_aux[10000];
	int num_cre[10000];
	int num_dec[10000];
	int aux;
	int opc;
	int c = 0;
	int d = 0;
	char Resp;
    
    for (int i = 0; i < 10000; i++){
					
		num[i] = rand() % 99;		
	}
    
    do{
        system("cls");        
        printf("\nMENU");
        printf("\n 1 - Imprimir o vetor");
        printf("\n 2 - Ordenar o vetor de forma crescente");
        printf("\n 3 - Ordenar o vetor de forma decrescente");
        printf("\n 4 - Imprimir o vetor de forma crescente");
        printf("\n 5 - Imprimir o vetor de forma decrescente");
		printf("\n 6 - Quantidade de numeros repetidos");        
        printf("\n 7 - Sair");

        printf("\nDigite uma opcao: ");
        scanf("%d", &opc);
        system("cls");

        switch(opc){
            case 1:
                printf("Gerando 10 valores aleatorios:\n\n");

				for (int i = 0; i < 10000; i++){
				    
				    printf("%d - ", num[i]);
				}
                
                break;
            case 2:
			    srand(time(NULL));
			    
			    for(int i = 0; i < 10000; i++){
			    
			    num_aux[i] = num[i];
				}	
			    
			    for(int i = 0; i < 10000; i++){
			     	
			    	for(int j = i + 1; j < 10000; j++){
			        	
			        	if(num[i] > num[j]){
			        		
			                aux    = num[i];
			                num[i] = num [j];
			                num[j] = aux;
			            }
			        }
			    }

			    for (int i=0; i<10000; i++){
			    		    	
			        printf ("%d - ",num[i]);
			    }
			    
			    for(int i = 0; i < 10000; i++){
			    num_cre[i] = num_aux[i];
			    
			    num[i] = num_aux[i];
				}
				
				c = 1;
                
                break;
            case 3:
            	srand(time(NULL));
			    
			    for(int i = 0; i < 10000; i++){
			    
			    num_aux[i] = num[i];
				}	
			    
			    for(int i = 0; i < 10000; i++){
			     	
			    	for(int j = i + 1; j < 10000; j++){
			        	
			        	if(num[i] < num[j]){
			        		
			                aux    = num[i];
			                num[i] = num [j];
			                num[j] = aux;
			            }
			        }
			    }

			    for (int i=0; i<10000; i++){
			    		    	
			        printf ("%d - ",num[i]);
			    }
			    
			    for(int i = 0; i < 10000; i++){
			    num_dec[i] = num_aux[i];
			    
			    num[i] = num_aux[i];
				}
				
				d = 1;
				
                system("pause");
				break;
			case 4:
				
            	if (c == 1){
	            	for (int i = 0; i < 10000; i++){
					    
					    printf("%d - ", num_cre[i]);
					}
				} else {
					
					printf ("Ainda não ordenado!!!\n\n\a");
				}
            	
				break;
			case 5:
				
				if (d == 1){
	            	for (int i = 0; i < 10000; i++){
					    
					    printf("%d - ", num_dec[i]);
					}
				} else {
					
					printf ("Ainda não ordenado!!!\n\n\a");
				}
				break;
			case 6:
            	
				break;			    
            case 7:
                printf ("\nEncerrando programa...\n\a");
	            	
	            return 0;
	            
                break;

            default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                system("pause");

        }
   		printf("\nDeseja realizar um novo pedido? (s/n) => ");
		fflush (stdin);
		scanf("%c", &Resp);
		
	} while (Resp == 's' || Resp == 'S');
}
