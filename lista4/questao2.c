/*
Quest�o 02:
Dada uma string s, desenvolver uma fun��o
que determine se s � ou n�o um pal�ndromo.
Observa��o: uma string s ser� um pal�ndromo
quando seus caracteres formarem a mesma
sequ�ncia, independente se s � percorrida da
esquerda para direita ou vice-versa.
*/

#include<stdio.h>
#include<string.h>

//Prot�tipo da fun��o
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
