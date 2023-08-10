/*
Questão 04:
Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.
*/

#include<stdio.h>

//Protótipo da função
int arquivoOrdenado(char nomeArq[]);


void main(){
	char nomeArquivo[20];
	int resultado;
	
	printf("Digite o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArquivo);
	
	resultado = arquivoOrdenado(nomeArquivo);
	
	switch(resultado){
		case -1: printf("\nERROR na abertura do arquivo");
				 break;
		
		case  1: printf("\nO arquivo esta ordenado");
				 break;
		
		case  0: printf("\nO arquivo nao esta ordenado");		 
	}
}

int arquivoOrdenado(char nomeArq[]){
	FILE *arq;
	int valor, anterior;
	
	arq = fopen(nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo
	if(!arq){
		return -1;
	}
	else{
		
		//lendo o primeiro valor do arquivo
		fscanf(arq, "%d", &anterior);
		
		while(fscanf(arq, "%d", &valor) != EOF){
			
			//Verificando se os elementos não estão ordenados
			if(valor < anterior){
				fclose(arq);
				
				return 0;
			}
			else{
				//Atualizando o 'anterior'
				anterior = valor;
			}
		}
		
		//Se chegou aqui, os elementos estão ordenados
		fclose(arq);
		
		return 1;
	}
}
