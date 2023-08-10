/*
QUEST�O 01:
Fa�a uma fun��o que, dada uma matriz M8�5 de
reais, gere a matriz M^t, sua transposta
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LI 8
#define CO 5

//Prot�tipo da fun��o
void transposta(int m[LI][CO], int mt[CO][LI]);
void preencherMatriz(int m[LI][CO]);
void exibirMatriz(int m[LI][CO]);
void exibirSubMatriz(int subM[CO][LI]);

void main(){
	int matriz[LI][CO], subMatriz[CO][LI];
	srand(time(NULL));
	
	preencherMatriz(matriz);
	transposta(matriz, subMatriz);
	
	exibirMatriz(matriz);
	
	printf("\n\n");
	
	exibirSubMatriz(subMatriz);
}

void preencherMatriz(int m[LI][CO]){
	int i, j;
	
	for(i = 0; i < LI; i++){
		
		for(j = 0; j < CO; j++){
			
			m[i][j] = rand() % 10;
		}
	}
}
void transposta(int m[LI][CO], int mt[CO][LI]){
	int i, j;
	
	for(i = 0; i < LI; i++){
		
		for(j = 0; j < CO; j++){
			
			mt[j][i] = m[i][j];
		}
	}
}

void exibirMatriz(int m[LI][CO]){
	int i, j;
	
	for(i = 0; i < LI; i++){
		
		printf("\n[  ");
		
		for(j = 0; j < CO; j++){
			printf("%d  ", m[i][j]);
		}
		
		printf("]");
	}
}

void exibirSubMatriz(int subM[CO][LI]){
	int i, j;
	
	for(i = 0; i < CO; i++){
		
		printf("\n[  ");
		
		for(j = 0; j < LI; j++){
			printf("%d  ", subM[i][j]);
		}
		
		printf("]");
	}
}
