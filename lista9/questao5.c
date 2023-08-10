/*
Quest�o 05:
Pede-se a implementa��o de uma fun��o
recursiva que exiba os n primeiros termos de
uma PG (Progress�o Geom�trica), onde a1 � o
seu primeiro termo e q a raz�o.
*/

#include<stdio.h>

//Prot�tipo da fun��o
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
