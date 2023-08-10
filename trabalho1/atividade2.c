/*
Desenvolver uma função que, dada uma string
str, substitua uma substring s1 de str (definida
pelas posições inicial e final) por outra string,
s2.

Exemplo:
str originalmente:
e   a i ,   v c   v  e  m  ?
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

str após a substituição:
e   a i ,   v o c e     v  e  m  ?
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/

#include<stdio.h>
#include<string.h>

#define TAM 50

//Protótipo da função
void substituirString(char str1[], char subStr[], char str2[], int posInicial, int posFinal, int quant);


void main(){
	char stringOrigem[TAM], subString[50], stringNovo[TAM];
	int posicaoInicial, posicaoFinal;
	
	printf("Digite a string original: ");
	fflush(stdin);
	gets(stringOrigem);
	
	printf("\nString: %s", stringOrigem);
	
	printf("\n\nDigite a string que voce deseja inserir: ");
	fflush(stdin);
	gets(stringNovo);
	
	printf("Digite a posicao inicial: ");
	scanf("%d", &posicaoInicial);
	
	printf("Digite a posicao final: ");
	scanf("%d", &posicaoFinal);
	
	substituirString(stringOrigem, subString, stringNovo, posicaoInicial, posicaoFinal, TAM);
	
	printf("\n\nSubstring: %s", subString);
}

void substituirString(char str1[], char subStr[], char str2[], int posInicial, int posFinal, int quant){
	int i, j, k = 0;
	
	//pecorrendo a string original
	for(i = 0; str1[i]; i++){
		
		//copiando os caracter para subString
		subStr[k] = str1[i];
		
		//verificando se o i é igual a posição original
		if(i == posInicial){
			
			//pecorrendo a stringNova
			for(j = 0; str2[j]; j++){
				
				//copiando os caracter para subString
				subStr[k] = str2[j];
				
				//atualizando o valor de k
				k++;
			}
			
			//dimuindo o valor de k para remover o '\0'
			k--;
			
			//atribuindo a posição final ao i	
			i = posFinal;
		}
		
		k++;
	}
	
	subStr[k] = '\0';
}
