#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>
#include <map>


using namespace std;

struct Materias{
   int codigo;
   char disciplina[100];
   int periodo;
};
typedef struct Materias tMaterias;

int main(){
	
    setlocale (LC_ALL, "Portuguese");

    int chave;
    int i = 1;
    int j;
    int tamLista;
    
    map<int, tMaterias> MapaLista;
    
    Materias mat;
    
    mat.codigo = 103;
    strcpy(mat.disciplina, "Estrutura de Dados");
    mat.periodo = 3;
    MapaLista[i] = mat;
   
    i++;
    mat.codigo = 203;
    strcpy(mat.disciplina, "Estrutura de Dados Avan�ado");
    mat.periodo = 4;
    MapaLista[i] = mat;
    
    i++;
    mat.codigo = 303;
    strcpy(mat.disciplina, "POO");
    mat.periodo = 5;
    MapaLista[i] = mat;
    
    printf("Informe a chave da disciplina:");
    scanf("%d",&chave);
    
    
    /* Se achou a chave pesquisada, escreve Encontrou, caso
    contrario Nao Encontrou */
    
    
    if(MapaLista.find(chave) == MapaLista.end()) {
    	printf("Chave da disciplina n�o encontrado:");
    }
    else {
    	printf("\nEncontrado o registro:");
        printf("\nC�digo: %d",MapaLista[chave].codigo);
        printf("\nDisciplina: %s",MapaLista[chave].disciplina);
        printf("\nPer�odo: %d\n",MapaLista[chave].periodo);
        
    }
	
	//Tamanho da Lista
	printf("\n\nTamanho da lista: %d",MapaLista.size());    
    
    tamLista=MapaLista.size();
    
    for (j=0;j<=tamLista;j++){
    
		printf("\nC�digo: %d",MapaLista[j].codigo);
        printf("\nDisciplina: %s",MapaLista[j].disciplina);
        printf("\nPer�odo: %d\n",MapaLista[j].periodo);
	}
    
    
    
    system("PAUSE");
    return 0;
}
