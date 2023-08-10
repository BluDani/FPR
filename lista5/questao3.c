/*
Desenvolver uma função que gere a seguinte
matriz M5?5:

1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LI 5
#define CO 5

//Protótipo da função
void preencherMatriz(int m[LI][CO]);
void exibirMatriz(int m[LI][CO]);

void main(){
	int matriz[LI][CO];
	srand(time(NULL));
	
	preencherMatriz(matriz);
	exibirMatriz(matriz);
}

void preencherMatriz(int m[LI][CO]){
	int i, j;
	
	for(i = 0; i < LI; i++){
		
		for(j = 0; j < CO; j++){
			
			m[i][j] = i + j + 1;
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
