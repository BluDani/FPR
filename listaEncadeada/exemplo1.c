#include <stdio.h>

//Prot�tipo das fun��es



void main ()
{
	//declara��o de vari�veis
	int i;
	int v1[5] = {1,2,3,4,5};
	int *p;
	
	//atribui��o
	p = v1;
	
	//exibindo os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%d (%p)\n", *p, p);
		p++;
	}
	
	printf("\n\n");
	
	//declara��o de vari�veis
	char v2[5] = {'a','b','c','d','e'};
	char *q;
	
	//atribui��o
	q = v2;
	
	//exibindo os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%c (%p)\n", *q, q);
		q++;
	}
}
