#include <stdio.h>

//Protótipo da função
int funcao(int a, int b);

void main(){
	printf ("Resposta = %d", funcao (10, 5));
}

int funcao(int a, int b){
	if(a > 0){
		if(a > b){
			return funcao (a-1, b+2) + funcao (b-a, b);
		}
		else{
			return funcao(a-2, b);
		}
	} 
	else{
		return b;
	}
}
