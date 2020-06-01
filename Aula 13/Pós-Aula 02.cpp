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

    int chave;
    
    map <int, string> myMap;
    
    myMap[68] = "AC";
    myMap[82] = "AL";
    myMap[96] = "AP";
    myMap[92] = "AM";
    myMap[72] = "BA";
    myMap[88] = "CE";
    myMap[61] = "DF";
    myMap[27] = "ES";
    myMap[62] = "GO";
    myMap[98] = "MA";
    myMap[65] = "MT";
    myMap[84] = "MS";
    myMap[31] = "MG";
    myMap[41] = "PR";
    myMap[83] = "PB";
    myMap[91] = "PA";
    myMap[81] = "PE";
    myMap[86] = "PI";
    myMap[21] = "RJ";
    myMap[84] = "RN";
    myMap[51] = "RS";
    myMap[69] = "RO";
    myMap[95] = "RR";
    myMap[48] = "SC";
    myMap[79] = "SE";
    myMap[11] = "SP";
    myMap[63] = "TO";
    
    printf ("Qual o DDD? ");
    scanf  ("%d", &chave);
    
    printf ("\n\nA UF do estado é: ");
    
    cout << myMap[chave] << endl;
    
    printf ("\n\n");
    
    system("PAUSE");
    return 0;
}
