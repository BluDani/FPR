/*
Quest�o 04:
Fazer uma fun��o recursiva que, dado um
n�mero inteiro N, exiba o mesmo na base 2
(bin�ria).
*/

#include<stdio.h>

//Prot�tipo da fun��o
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
