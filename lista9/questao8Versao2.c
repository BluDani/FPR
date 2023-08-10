/*
	FAETERJ-Rio
	FPR Manh� - 01/06/2022
	
	Lista de Exerc�cios IX (Recursividade)
	
	Quest�o 08:
	Desenvolver uma fun��o recursiva que, dada uma string, exiba-a 
	invertida.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos das fun��es
void inverter (char s[]);

//main
void main ()
{
	inverter ("ALGORITMOS");
}

//implementa��o das fun��es
void inverter (char s[])
{
	if (*s)	//caso geral
	{
		inverter (s+1);
		printf ("%c", *s);
		//printf ("%c %p\n", *s, s);
	}
}
