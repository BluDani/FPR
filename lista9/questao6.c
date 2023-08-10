/*
Questão 06:
Dada uma string s, desenvolver uma função recursiva que determine 
se s é ou não um palíndromo.
*/

#include<stdio.h>
#include<string.h>

//Protótipo de função
int palindromo(char str[]);
int palindromoRec(char str[], int inicio, int fim);


void main(){
	
	printf("Arara: %d\n", palindromo("arara"));
}

int palindromo(char str[]){
	
	return palindromoRec(str, 0, strlen(str)-1);
}

int palindromoRec(char str[], int inicio, int fim){
	
	if(inicio < fim){ //caso geral
		
		if(str[inicio] != str[fim]){	//caso base
			
			return 0;
		}
		else{
			
			return palindromoRec(str, inicio+1, fim-1);
		}
	}
	else{
		
		return 1;	//caso base
	}
}
