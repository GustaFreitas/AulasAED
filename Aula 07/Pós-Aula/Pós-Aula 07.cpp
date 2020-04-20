#include <conio.h>
#include <iostream>
#include <locale.h>
#include <stack>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void Preencher(stack <int> pilha);
void Menu(stack <int> pilha);
void Imprime(stack <int> pilha);
void Informacoes(stack <int> pilha);
void Busca(stack <int> pilha);
void Cursor(int x, int y);
void Remover(stack <int> pilha);
void Remover_Tudo(stack <int> pilha);


void Cursor(int x, int y)
{
     SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void Menu(stack <int> pilha)
{
	int opcao;
	system("cls");
    system("color 2D");
    printf("\t\t##############################\n");
    printf("\t\t# MENU DE OPERAÇÕES COM PILHA #\n");
    printf("\t\t##############################\n\n");

    printf("1 - INSERIR ELEMENTOS NA PILHA \n2 - BUSCAR ELEMENTO NA PILHA \n3 - REMOVER ELEMENTO NA PILHA \n4 - IMPRIMIR A PILHA \n5 - INFORMAÇÕES SOBRE A PILHA \n6 - LIMPAR A PILHA \n7 - SAIR\n\nInforme a opção desejada:[  ]");
    Cursor(27,13);
	scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        system("cls");
        printf("PREENCHER\n");
        Preencher(pilha);
        break;
    case 2:
        system("cls");
        printf("BUSCAR\n");
        Busca(pilha);
        break;
    case 3:
        system("cls");
        printf("REMOVER ELEMENTO NA PILHA:\n");
        Remover(pilha);
        break;
    case 4:
        system("cls");
        printf("IMPRIMIR A PILHA:\n");
        Imprime(pilha);
        break;
    case 5:
        system("cls");
        printf("INFORMAÃ‡Ã•ES DA PILHA\n");
        Informacoes(pilha);
        break;

     case 6:
        system("cls");
        Remover_Tudo(pilha);
        getch();
        break;

    case 7:
        system("cls");
        printf("Obrigado e Tchau! Pressione qualquer tecla para continuar\n");
        getch();
        break;

    default:
        printf("Voce deve escolher uma opcao valida\n");
        system("pause");
        system("cls");
        Menu(pilha);
    }
}

void Preencher(stack <int> pilha){
	int i,valor;
		for(i=0;i<10;i++){
			valor = rand() % 100 +1;
			pilha.push(valor);
		}
	printf("\n!!Lista preenchida com 10 elementos !!");
	getch();
	Menu(pilha);

}

void Imprime(stack <int> pilha){
	stack <int> pilha_temp;
	pilha_temp = pilha;

		if(pilha_temp.empty()){
			printf("\n!! A pilha estÃ¡ VAZIA !!");
		}else{
			 printf("\n\nINICIO: --> ");
			while(!pilha_temp.empty()){
				printf("%d - ", pilha_temp.top());
				pilha_temp.pop();
			}
			printf("<-- FIM\n");
		}
		getch();
		Menu(pilha);
}

void Informacoes(stack <int> pilha){
    if(!pilha.empty()){
		printf("\tTamanho da pilha: %d \n", pilha.size());
		printf("\tPrimeiro elemento da Pilha: %d \n", pilha.top());
		printf("\n\n");
	}else {
		printf("\nA Pilha estÃ¡ vazia. Impossivel fornecer informaÃ§Ãµes\n");
	}
	getch();
	Menu(pilha);
}


void Remover(stack <int> pilha){
	printf("\nREMOVENDO O VALOR %d DA PILHA:", pilha.top());
	pilha.pop();
	printf("\nITEM REMOVIDO. O PRIMEIRO DA PILHA AGORA Ã‰ O VALOR %d.", pilha.top());
	getch();
	Menu(pilha);
}


void Remover_Tudo(stack <int> pilha){
	printf("\nREMOVENDO TODOS ELEMENTOS DA PILHA");
	while(!pilha.empty())
	{
	pilha.pop();
	}
	printf("\nTodos elementos da pilha foram removidos");
	getch();
	Menu(pilha);
}


void Busca(stack <int> pilha
){
	stack <int> pilha_temp;
	int valor;

	pilha_temp = pilha;

	printf("Informe o valor a ser pesquisado na pilha:");
	scanf("%d",&valor);
		while(!pilha_temp.empty()){
			if (pilha_temp.top() == valor)
			{
				printf("Valor %d encontrado na pilha", valor);
				getch();
				Menu(pilha);
				exit;
			}
		pilha_temp.pop();
		}
    printf("Valor %d  NÃO encontrado na pilha", valor);
    getch();
    Menu(pilha);
	exit;
}

int main(){
   stack<int> pilha;
   setlocale(LC_ALL, "Portuguese");
   Menu(pilha);
}
