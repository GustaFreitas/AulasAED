#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <map>

using namespace std;

struct DDD {
	
   char UF [2];
   
};

typedef struct DDD dddUF;

int main(){
	
    setlocale (LC_ALL, "Portuguese");

    char chave[7];
    
    map <string, string> myMap;
    
    myMap["AAA1111"] = "VW Gol";
    myMap["BBB2222"] = "Fiat Uno";
    myMap["CCC3333"] = "GM Onix";
    myMap["DDD4444"] = "Fiat Palio";
    myMap["EEE5555"] = "Fiat Strada";
    myMap["FFF6666"] = "VW Fox";
    myMap["GGG7777"] = "Hyundai HB20";
    myMap["HHH8888"] = "Renault Sandero";
    myMap["III9999"] = "Ford Ka";
    myMap["JJJ0000"] = "Fiat Siena";

    
    printf ("Informe a placa: ");
    scanf  ("%s", &chave);
    
    printf ("\n\nO modelo dp carro: ");
    
    cout << myMap[chave] << endl;
    
    printf ("\n\n");
    
    system("PAUSE");
    return 0;
}
