/* 
Desenvolver uma função recursiva que, dados dois 
números inteiros n1 e n2, determine a quantidade de 
divisores que eles possuem em comum. 
*/

#include<stdio.h>
#include<stdlib.h>

//Protótipos das funções
int verificaDivisor(int num1, int num2);
void verificaDivisorRec(int num1, int num2, int i, int *cont);

void main(){
	
	int valor1, valor2, res;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &valor1);
	
	printf("Digite o segundo valor: ");
	scanf("%d", &valor2);
	
	res = verificaDivisor(valor1, valor2);
	
	printf("\nOs numeros %d e %d possuem %d divisores em comum", valor1, valor2, res);
}

int verificaDivisor(int num1, int num2){
	
	int cont = 0, menor;
	
	if(num1 < num2){
		
		menor = num1;
	}
	else{
		
		menor = num2;
	}
	
	verificaDivisorRec(num1, num2, menor, &cont);
	
	return cont;
}

void verificaDivisorRec(int num1, int num2, int i, int *cont){
	
	if(i >= 1){
		
		if((num1 % i == 0) && (num2 % i == 0)){
			
			(*cont)++;
		}
		
		verificaDivisorRec(num1, num2, i - 1, cont);
	}
}
