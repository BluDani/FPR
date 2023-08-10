/*
Questão 03:
Desenvolver uma função recursiva que exiba
todos os múltiplos do número N, inferiores ou
iguais ao valor V.
*/

#include<stdio.h>

//Protótipo da função
void multiplos(int mult, int valor);


void main(){
	int n, v;
	
	printf("Digite o multiplo: ");
	scanf("%d", &n);
	
	printf("Digite o valor: ");
	scanf("%d", &v);
	
	multiplos(n, v);
}

void multiplos(int mult, int valor){
	
	if(mult <= valor){
		
		multiplos(mult, valor - 1);
		
		if(valor % mult == 0){
			
			printf("%d ", valor);
			
		}
	}
}
