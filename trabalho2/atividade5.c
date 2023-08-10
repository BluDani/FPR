/*
Desenvolver uma função recursiva que, dado
um número inteiro n, determine a quantidade
de divisores deste número.
*/

#include<stdio.h>

//Protótipo das funções
int quantDiv(int num);
void quantDivRec(int num, int i, int *cont);

int main(){
	int numero, res;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	res = quantDiv(numero);
	
	printf("\nO numero %d tem %d divisores", numero, res);
}

int quantDiv(int num){
	
	int cont = 0;
	
	quantDivRec(num, num, &cont);
	
	return cont;
}

void quantDivRec(int num, int i, int *cont){
	
	if(i >= 1){
		
		if(num%i == 0){
			(*cont)++;
			
		}
		
		quantDivRec(num, i-1, cont);
	}
}
