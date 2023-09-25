/*
	FAETERJ-Rio
	FPR - Manhã (25/05/2023)
	
	Ponteiros
	
	Exemplo 4
*/

//importação de bibliotecas
#include <stdio.h>

void main ()
{
	//declaração de variáveis
	int i;
	int v[5] = {1,2,3,4,5};
	//int *p;
	
	//atribuição
	//p = v;
	
	//exibindo os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%d ", *(v+i));
		//p++;
	}
}
