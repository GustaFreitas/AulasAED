#include <iostream>
#include <stack>

using namespace std;

void imprime_pilha (stack <int> pilha)
{
	printf ("Pilha: \n");
	
	while (!pilha.empty())
	{
		printf ("%d \n", pilha.top());
		
		pilha.pop();
	}
	printf ("\n");
}

int main () 
{	
	stack<int> pilha;
	
	pilha.push(10);
	pilha.push(9);
	pilha.push(8);
	pilha.push(7);
	
	imprime_pilha (pilha);
}
