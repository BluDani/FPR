/*
	FAETERJ-Rio
	FPR Manhã - 01/06/2022
	
	Lista de Exercícios IX (Recursividade)
	
	Questão 08:
	Desenvolver uma função recursiva que, dada uma string, exiba-a 
	invertida.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void inverter (char s[]);

//main
void main ()
{
	inverter ("ALGORITMOS");
}

//implementação das funções
void inverter (char s[])
{
	if (*s)	//caso geral
	{
		inverter (s+1);
		printf ("%c", *s);
		//printf ("%c %p\n", *s, s);
	}
}
