/*
	FAETERJ-Rio
	FPR - Manh� (25/05/2023)
	
	Ponteiros
	
	Exemplo 4
*/

//importa��o de bibliotecas
#include <stdio.h>

void main ()
{
	//declara��o de vari�veis
	int i;
	int v[5] = {1,2,3,4,5};
	//int *p;
	
	//atribui��o
	//p = v;
	
	//exibindo os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%d ", *(v+i));
		//p++;
	}
}
