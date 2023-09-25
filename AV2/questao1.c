/*
Questão 01 [2,5 pontos]:
Desenvolver uma função recursiva que, dado um número inteiro n1, “crie” um novo número inteiro, n2, consistindo no
primeiro com os algarismos invertidos.
Exemplos:

n1 = 4258 n2 será igual a 8524
n2 = 12625 n2 será igual a 52621
*/

#include<stdio.h>
#include<stdlib.h>

//Protótipos da função
void inverteNumero(int num, int *num2);

void main(){
	
	int valor, num2 = 0, res = 0;
	
	printf("Digite um numero: ");
	scanf("%d", &valor);
	
	inverteNumero(valor, &res);
	
	printf("\nN2 = %d", res);
}

void inverteNumero(int num, int *num2){
	
	if(num > 0){
		
		(*num2)= (num % 10) + ((*num2) * 10);
		
		inverteNumero(num / 10, num2);
		
	}

}

