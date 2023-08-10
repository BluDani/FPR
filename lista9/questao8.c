/*
Quest�o 08:
Desenvolver uma fun��o recursiva que, dada uma string, exiba-a 
invertida.
*/

#include <stdio.h>
#include <string.h>

//Prot�tipos das fun��es
void inverter(char str[]);
void inverterRec(char str[], int pos);

void main(){
	
	inverter("ALGORITMO");
}

void inverter(char str[]){
	
	inverterRec(str, strlen(str)-1);
}

void inverterRec(char str[], int pos){
	
	if(pos >= 0){	//caso geral
		
		printf("%c", str[pos]);
		inverterRec(str, pos-1);
		
	}
}
