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
  
  float HS = 3804853940604895232;
  
  float hash;
  
  for (int i=0; i <= 99999; i++){
  	hash = calcula_hash_inteiro(i);
  	if (hash == HS){
  		printf ("A senha descoberta é: %d", i);
  		break;
	  }
	}
}
