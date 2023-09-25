/*
Questão 01 [2,5 pontos]:
Dada uma matriz MLxC, onde L e C são constantes,
desenvolver uma função que “troque” os elementos de
duas colunas c1 e c2, respeitadas as seguintes regras:

a. A troca só será possível se as colunas c1 e c2
existirem na matriz. Caso existam, a troca será
realizada e o valor 1 retornado pela função;
por outro lado, 0 será retornado se uma ou as
duas colunas forem inválidas;

b. Após a troca, a coluna c2 conterá exatamente
os elementos originais da coluna c1, na
mesma ordem. Porém, os valores da coluna c1
serão os originais da c2, na ordem inversa.
Exemplo:

Trocar as colunas 1 e 3 da matriz abaixo:
1 3 5 7 9
4 6 5 8 0
3 4 5 7 8
5 9 1 2 3
7 1 5 3 5
4 0 2 1 5

1 1 5 3 9
4 3 5 6 0
3 2 5 4 8
5 7 1 9 3
7 8 5 1 5
4 7 2 0 5 

*/

#include<stdio.h>

#define LI 6
#define CO 5

//Protótipo da função
void preencherMatriz(int m[LI][CO]);
void exibirMatriz(int m[LI][CO]);
int trocarElementos(int m[LI][CO], int c1, int c2);

void main(){
	int matriz[LI][CO];
	int coluna1, coluna2, resultado;
	
	srand(time(NULL));
	
	preencherMatriz(matriz);
	exibirMatriz(matriz);
	
	printf("\n\nDigite qual coluna voce quer trocar: ");
	scanf("%d", &coluna1);
	
	printf("Digite qual coluna voce quer que seja trocada: ");
	scanf("%d", &coluna2);
	
	resultado = trocarElementos(matriz, coluna1, coluna2);
	if(resultado == 0){
		printf("\n[ERROR] Coluna invalida");
	}
	else{
		printf("\nTroca realizada com sucesso");
		exibirMatriz(matriz);
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

int trocarElementos(int m[LI][CO], int c1, int c2){
	int i, j, anterior[LI];
	c1 -= 1;
	c2 -= 1;
	
	if((c1 > CO) || (c1 < CO) || (c2 > CO) || (c2 < CO)){
		return 0;
	}
	else{
		for(i = 0, j = LI - 1; i < LI; i++, j--){
			anterior[i] = m[i][c1];
			
			m[i][c1] = m[j][c2];
		}
	
		for(i = 0; i < LI; i++){
			m[i][c2] = anterior[i];
		}
		
	}
	
	return 1;
}
