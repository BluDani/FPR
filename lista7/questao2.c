/*
Questão 02:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.
*/

#include<stdio.h>

//Protótipo da função
int quantidadeCaracter(char nomeArq[], char caracter);


void main(){
	char nomeArquivo[20];
	char caracter;
	int quant;
	
	printf("Digite o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArquivo);
	
	printf("DIgite o caracter: ");
	scanf("%c", &caracter);
	
	quant = quantidadeCaracter(nomeArquivo, caracter);
	
	if(quant == -1){
		printf("\nErro na abertura do arquivo");
	}
	else{
		printf("\nO caracter %c apaereceu %d vezes no arquivo %s", caracter, quant, nomeArquivo);
	}
}

int quantidadeCaracter(char nomeArq[], char caracter){
	FILE *arq;
	char ch;
	int cont = 0;
	
	arq = fopen(nomeArq, "r");
	
	if(!arq){
		return -1;
	}
	else{
		
		caracter = toupper(caracter);
		
		while(fscanf(arq, "%c", &ch) != EOF){
			
			if(toupper(ch) == caracter){
				cont++;
			}
		}
		
		fclose(arq);
		
		return cont;
	}
}
