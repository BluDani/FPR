/*
Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).
*/

#include<stdio.h>

//Protótipo da função
void binario(int n);


void main(){
	int num;
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	binario(num);
}

void binario(int n){
	
	if(n >= 1){
		
		binario(n / 2);
		
		printf("%d", n%2);
		
		/*
		if(n % 2 == 0){
			printf("0");
		}
		else{
			printf("1");
		}
		*/
	}
}
