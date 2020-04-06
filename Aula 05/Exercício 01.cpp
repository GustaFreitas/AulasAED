#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//Estrutura base do n�.
struct node
{
    int nData;
    struct node *pLink;
};
 
 
//Fun��o pra printar o n� na tela.
void displayLL (struct node *p)
{
    printf("Mostrando a lista:\n"); 
    if(p)
    {
        do
        {
            printf(" %d", p->nData);
            p=p->pLink;
        }
        while(p);
    }
    else
        printf("Lista vazia.");
}
 
 
 
int main(void)
{
	setlocale (LC_ALL, "Portuguese");
	
    struct node *pNode1 = NULL;
    struct node *pNode2 = NULL;
    struct node *pNode3 = NULL;
     
    //Criando os nos e associando os dados.
    pNode1 = (struct node*) malloc(sizeof(struct node*));
    pNode1->nData = 10;
     
    pNode2 = (struct node*) malloc(sizeof(struct node*));
    pNode2->nData = 20;
     
    pNode3 = (struct node*) malloc(sizeof(struct node*));
    pNode3->nData = 30;
     
    //Conectando os n�s
    pNode1->pLink = pNode2;
    pNode2->pLink = pNode3;  
    pNode3->pLink = NULL;
     
    //Mostrando a lista.
    if(pNode1)  
        displayLL(pNode1);
  
  return 0;
}
