#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define ZEROABSC -273.15
#define ZEROABSF -459.67

float leTemperatura(int opcao);

float converteTemperatura(int opcao, float *temperatura);

int main(void)
{
	setlocale (LC_ALL, "Portuguese");
	
	float temp, conv;
    int op;

    do
	{
		system("CLS");
		
        printf("1 - Celsius para Fahreinheit\n");
        printf("2 - Fahrenheit para Celsius\n");
        printf("3 - Sair.\n\n");
        printf("Op��o: ");
        scanf("%d", &op);
        
        switch(op)
		{
            case 1:
            	
				temp = leTemperatura(op);
				
                conv = converteTemperatura(op, &temp);
                
                printf("\n%.2f �C s�o %.2f �F.\n\n", temp, conv);
                
                system("PAUSE");
                
            break;
            case 2:
            	
				temp = leTemperatura(op);
				
                conv = converteTemperatura(op, &temp);
                
                printf("\n%.2f �F s�o %.2f �C.\n\n", temp, conv);
                
                system("PAUSE");
                
            break;
            case 3:
            	
				printf("\nSaindo...\n");
			
            break;
            
            default:
			
			printf("\nValor inv�lido.\n\n");
			
			system("PAUSE");
        }
        
    }
	while(op != 3);
    
    return 0;
}

float leTemperatura(int opcao)
{
    float temperatura;
    bool teste;
    
    do
	{
        printf("\nDigite a temperatura: ");
        scanf("%f", &temperatura);
        
        if( ((opcao == 1) && (temperatura < ZEROABSC)) || ((opcao == 2) && (temperatura < ZEROABSF)) )
		{
            printf("\n1Temperatura inv�lida. Digite novamente.\n");
            teste = false;
        }
        else 
        {
            teste = true;
    	}
    }
	while(!teste);
	
    return temperatura;
}

float converteTemperatura(int opcao, float *temperatura)
{
    int conversao;
    
    if(opcao == 1)
    {
	    conversao = *temperatura * 1.8 + 32;
	}
	else
    {
	    conversao = (*temperatura - 32) / 1.8;
	}
	
	return conversao;
}

