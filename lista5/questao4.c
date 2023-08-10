/*
QUEST�O 04:
Fazer uma fun��o que, dada uma matriz M6�6,
determine se ela � sim�trica.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LI 6
#define CO 6

//Prot�tipo da fun��o
int simetrica(int m[LI][CO]);


void main(){
	int matriz[LI][CO];
	
	simetrica(matriz);
}

int simetrica(int m[LI][CO]){
	int i, j;
	
	for(i = 0; i < LI - 1; i++){
		
		for(j = i + 1; j < CO; j++){
			
			if(m[i][j] != m[j][i]){
				return 0;
			}
		}
	}
	
	return 1;
}
