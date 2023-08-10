#include<stdio.h>

//Protótipo da função
int funcao (int A, int B);


void main(){
	int x;
	
	x = funcao(32, 6);
	
	printf("%d", x);
}

int funcao (int A, int B){
	
	if (A >= B){
		
		return funcao (A-B, B);
	}
	else{
		
		return A;
	}
}
