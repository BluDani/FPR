/*
QUESTÃO 02:
Desenvolver uma função que, dada uma matriz
M15×20, determine se um número X se encontra
na linha L da matriz.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Protótipo da função
void preencherMatriz(int m[15][20]);
void exibirMatriz(int m[15][20]);
int encontrarNumero(int m[15][20], int n, int l);

void main(){
	int matriz[15][20], numero, linha, resultado;
	srand(time(NULL));
	
	preencherMatriz(matriz);
	exibirMatriz(matriz);
	
	printf("\n\nQual numero voce quer encontrar? ");
	scanf("%d", &numero);
	
	printf("Em qual linha voce quer verificar? ");
	scanf("%d", &linha);
	
	resultado = encontrarNumero(matriz, numero, linha);
	
	if(resultado == 0){
		printf("Numero nao encontrado");
	}
	else{
		printf("Numero encontrado");
	}
}

void preencherMatriz(int m[15][20]){
	int i, j;
	
	for(i = 0; i<15; i++){
		
		for(j = 0; j < 20; j++){
			
			m[i][j] = rand() % 10;
		}
	}
}

void exibirMatriz(int m[15][20]){
	int i, j;
	
	for(i = 0; i < 15; i++){
		
		printf("\n[  ");
		
		for(j = 0; j < 20; j++){
			printf("%d  ", m[i][j]);
		}
		
		printf("]");
	}
}

int encontrarNumero(int m[15][20], int n, int l){
	int i, j;
	
	for(j = 0; j < 20; j++){
		
		if(m[l][j] == n){
			return 1;
		}
	}
	
	return 0;
}
