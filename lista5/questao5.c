/*
QUESTÃO 05:
Implementar uma função que, dada uma matriz
M10×8, gere um vetor V de tamanho 8, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LI 10
#define CO 8

//Protótipo da função
void preencherMatriz(int m[LI][CO], int vetor[]);
void exibirMatriz(int m[LI][CO]);
void exibirVetor(int vetor[], int quant);

void main(){
	int matriz[LI][CO], vetor[CO];
	srand(time(NULL));
	
	preencherMatriz(matriz, vetor);
}

void preencherMatriz(int m[LI][CO], int vetor[]){
	int i, j;
	
	for(i = 0; i < LI; i++){
		
		for(j = 0; j < CO; j++){
			
			m[i][j] = rand() % 10;
			
			if(i == 0){
				vetor[j] = m[i][j];
			}
			else{
				vetor[j] += m[i][j];
			}
		}
	}
	
	exibirMatriz(m);
	
	exibirVetor(vetor, CO);
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

void exibirVetor(int vetor[], int quant){
	int i;
	
	printf("\n\nVetor =");
	
	for(i = 0; i < quant; i++){
		
		printf(" %d", vetor[i]);
	}
}
