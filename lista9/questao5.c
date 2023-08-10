/*
Questão 05:
Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o
seu primeiro termo e q a razão.
*/

#include<stdio.h>

//Protótipo da função
void exibindoPG(int a, int r, int n);


void main(){
	int termo, razao, num;
	
	printf("Digite o primeiro termo: ");
	scanf("%d", &termo);
	
	printf("Digite a razao: ");
	scanf("%d", &razao);
	
	printf("Digite o numero de termos: ");
	scanf("%d", &num);
	
	exibindoPG(termo, razao, num);
}

void exibindoPG(int a, int r, int n){
	
	if(n > 0){
		
		printf("%d  ", a);
		
		exibindoPG(a * r, r, n - 1);
		
	}
}
