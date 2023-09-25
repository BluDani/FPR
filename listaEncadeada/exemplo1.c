#include <stdio.h>

//Protótipo das funções



void main ()
{
	//declaração de variáveis
	int i;
	int v1[5] = {1,2,3,4,5};
	int *p;
	
	//atribuição
	p = v1;
	
	//exibindo os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%d (%p)\n", *p, p);
		p++;
	}
	
	printf("\n\n");
	
	//declaração de variáveis
	char v2[5] = {'a','b','c','d','e'};
	char *q;
	
	//atribuição
	q = v2;
	
	//exibindo os elementos do vetor
	for (i=0;i<5;i++)
	{
		printf ("%c (%p)\n", *q, q);
		q++;
	}
}
