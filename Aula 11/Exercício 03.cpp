#include <iostream>
#include <tr1/functional>
#include <string>
#include <locale.h>
#include <conio.h>

//funcao para calcular hash de numeros inteiros
float calcula_hash_inteiro(int valor){
  std::tr1::hash<float> hash_fn;  //Definição do Tipo de Dados Hash chamado hash_fn
  size_t str_hash = hash_fn(valor); //Faz o calculo do HASH
  return(str_hash); //Retorna o Hash
}


int main()
{

  setlocale (LC_ALL, "Portuguese");
  
  float HS = 10608169548643303424;
  int senha;
  
  float hash;

  	system ("cls");
  	printf ("Digite a senha ->  ");
  	scanf  ("%d", &senha);
  	hash = calcula_hash_inteiro(senha);
  	
  	FILE *arquivo;

    arquivo = fopen("password.txt","wt");
    
    fprintf(arquivo, "%d", hash);
    
    fclose(arquivo);
}
