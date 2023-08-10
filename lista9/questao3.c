/*
Quest�o 03:
Desenvolver uma fun��o recursiva que exiba
todos os m�ltiplos do n�mero N, inferiores ou
iguais ao valor V.
*/

#include<stdio.h>

//Prot�tipo da fun��o
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
