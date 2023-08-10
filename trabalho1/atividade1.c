/*
Dada uma matriz MLINHAxCOLUNA, onde LINHA e
COLUNA são constantes, e uma coluna C,
desenvolver uma função que desloque todos os
elementos da coluna C para a última coluna da
matriz.
Consequentemente, as colunas C+1 à última
deverão serão deslocadas uma posição para a
esquerda, conforme ilustrado no exemplo
abaixo:

Exemplo:

1 5 7 1 4 6
6 2 1 4 7 7
3 6 9 7 0 1
2 4 5 7 2 4
2 4 8 9 1 2

C = 1 (ou seja, a 2a coluna)

1 7 1 4 6 5
6 1 4 7 7 2
3 9 7 0 1 6
2 5 7 2 4 4
2 8 9 1 2 4

Nota: se o valor de C for válido, a função
fará o que foi solicitado e retornará 1, ao
final; caso contrário, apenas retornará 0.
*/

#include<stdio.h>
#include<time.h>

#define LI 5
#define CO 6

//Protótipo de função
void preencherMatriz(int m[LI][CO]);
void exibirMatriz(int m[LI][CO]);
int moverColuna(int m[LI][CO], int coluna);

void main(){
	int matriz[LI][CO];
	int coluna, res;
	srand(time(NULL));
	
	preencherMatriz(matriz);
	exibirMatriz(matriz);
	
	printf("\n\nDigite a coluna que deseja trocar: ");
	scanf("%d", &coluna);
	
	res = moverColuna(matriz, coluna);
	
	if(res == 1){
		printf("\nColuna movida com sucesso!");
			
		exibirMatriz(matriz);
	}
	else{
		printf("\n[ERROR] Nao foi possivel mover a coluna");
	}
}

void preencherMatriz(int m[LI][CO]){
	int i, j;
	
	for(i = 0; i < LI; i++){
		
		for(j = 0; j < CO; j++){
			
			m[i][j] = rand() % 10;
		}
	}
}

void exibirMatriz(int m[LI][CO]){
	int i, j;
	
	for(i = 0; i < LI; i++){
		
		printf("\n[ ");
		
		for(j = 0; j < CO; j++){
			
			printf("%d ", m[i][j]);
		}
		
		printf("]");
	}
}

int moverColuna(int m[LI][CO], int coluna){
	int i, j, valor;
	
	//diminuindo o valor para igualar a linha
	coluna--;
	
	//verificando se a coluna enviada é valida
	if((coluna >= 0) && (coluna <= CO - 1)){
		
		//varrendo a linha da matriz
		for(i = 0; i < LI; i++){
			
			//armazenando o valor da coluna pedida
			valor = m[i][coluna];
			
			//varrendo a coluna a partir da coluna pedida
			for(j = coluna; j < CO - 1; j++){
				
				//trocando as colunas
				m[i][j] = m[i][j + 1];
			}
			
			//armazenando o valor da coluna pedida no final
			m[i][j] = valor;
		}
		
		return 1;
	}
	else{
		
		return 0;
	}
	
}
