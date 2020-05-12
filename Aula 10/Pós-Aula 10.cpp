#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

FILE* AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo){
        case 'g':
            arquivo = fopen(caminho,"wt");
            break;
        case 'l':
            arquivo = fopen(caminho,"rt");
            break;
        case 'a':
            arquivo = fopen(caminho,"a");
            break;
    }
    if(arquivo==NULL){      //Se houver algum erro, o ponteiro apontará para NULL
        printf ("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void FecharArquivo(FILE *arquivo){
    fclose(arquivo);
}

void Cadastra(char nome[30], int telefone){
    FILE *arquivo;
    arquivo = AbreArquivo('a', "agenda.txt");
    fprintf (arquivo, "%s %d\n", nome, telefone);
    FecharArquivo(arquivo);
}

void Listar(){
    FILE *arquivo;
    char nome[30];
    int telefone;

    arquivo = AbreArquivo('l',"agenda.txt");
    
	//feof -> Verifica se é o fim do arquivo
    while(!feof(arquivo)){
        fscanf  (arquivo,"%s %d ", &nome, &telefone); // Le do arquivo
        printf ("Nome: %s  -  Telefone: %d\n", nome, telefone);
    }
    FecharArquivo(arquivo);
}

void PesquisarNome (char pesq_Nome[30]){
	FILE *arquivo;
    char nome[30];
    int telefone;
	
	arquivo = AbreArquivo('l',"agenda.txt");
	while(!feof(arquivo)){
		fscanf  (arquivo,"%s %d", &nome, &telefone);
		if(strcmp(pesq_Nome, nome) == 0){
			printf ("Nome encontrado\nNome: %s  -  Telefone: %d\n", nome, telefone);
		}
	}
	FecharArquivo(arquivo);
}

void PesquisarTelefone (int pesq_Tele){
	FILE *arquivo;
    char nome[30];
    int telefone;
	
	arquivo = AbreArquivo('l',"agenda.txt");
	while(!feof(arquivo)){
		fscanf  (arquivo,"%s %d", &nome, &telefone);
		if(pesq_Tele == telefone){
			printf ("Telefone encontrado\nNome: %s  -  Telefone: %d\n", nome, telefone);
		}
	}
	FecharArquivo(arquivo);
}

void Pesquisar(){
	
    FILE *arquivo;
    char pesq_Nome[30];
    int pesq_Tele; 
	int op;

    arquivo = AbreArquivo('l',"agenda.txt");
    
    system ("cls");
        printf ("\nMENU DE PESQUISA");
        printf ("\n 1 - Pesquisar por nome");
        printf ("\n 2 - Pesquisar por número");
        printf ("\n 3 - Sair");
        
        printf ("\nDigite uma opcao: ");
        scanf  ("%d", &op);
        system ("cls");
    
    switch (op){
    	case 1:
    		char pesq_Nome[30];
    		printf ("Digite o nome:");
    		scanf  ("%s", pesq_Nome);
    		PesquisarNome (pesq_Nome);
    		system ("PAUSE");
    		break;
    	case 2:
    		int pesq_Tele[30];
    		printf ("Digite o nome:");
    		scanf  ("%d", pesq_Tele);
    		PesquisarTelefone (pesq_Tele[30]);
    		system ("PAUSE");
    		break;
    	case 3:
    		exit(0);
    		break;
    	default:
    		printf ("\n\nOpção inválida! Tente Novamente!\n\n");
            system ("PAUSE");
	}
    
    
	//feof -> Verifica se é o fim do arquivo
    while(!feof(arquivo)){
        fscanf  (arquivo,"%s %d ", &pesq_Nome, &pesq_Tele); // Le do arquivo
        printf ("Nome: %s  -  Telefone: %d\n", pesq_Nome, pesq_Tele);
    }
    FecharArquivo(arquivo);
}

int main(){
	
	setlocale (LC_ALL, "Portuguese");
	
    int opcao;
    char nome[30];
    int telefone;
    do{
        system ("cls");
        printf ("\n\n\t\tBem Vindo ao programa AGENDA\n");
        printf ("\nMENU");
        printf ("\n 1 - Cadastrar Nome e telefone");
        printf ("\n 2 - Listar todos os Nomes e telefones");
        printf ("\n 3 - Pesquisar");
        printf ("\n 4 - Sair");

        printf ("\nDigite uma opcao: ");
        scanf  ("%d", &opcao);
        system ("cls");

        switch(opcao){
            case 1:
                printf ("\nDigite o nome: ");
                setbuf(stdin,NULL); //buffer está limpo para receber uma nova entrada de dados
                gets(nome);
                printf ("\nDigite o telefone: ");
                scanf  ("%d", &telefone);
                Cadastra(nome, telefone);
                system ("PAUSE");
                break;
            case 2:
                Listar();
                system ("PAUSE");
                break;
            case 3:
            	Pesquisar();
            	system ("PAUSE");
            	break;
            case 4:
                printf ("\n\nFinalizando...\n\n");
                system ("PAUSE");
                exit(0);
                break;

            default:
                printf ("\n\nOpcao invalida! Tente Novamente!\n\n");
                system ("PAUSE");

        }
    }while(opcao!=3);

    return 0;
}
