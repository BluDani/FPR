/*
Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.
*/

#include<stdio.h>
#include<string.h>

//Protótipo da função
int palindromo(char str[]);

void main(){
	char string[20] = "arara";
	int resultado;
	
	resultado = palindromo(string);
	
	if(resultado == 0){
		printf("Nao e um palindromo");
	}
	else{
		printf("E um palindromo");
	}
}

int palindromo(char str[]){
	int i, j;
	
	for(i=0, j = strlen(str) - 1; i < j; i++, j--){
		
		if(str[i] != str[j]){
			return 0;
		}
	}
	
	return 1;
}
