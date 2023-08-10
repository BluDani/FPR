/*
Questão 03:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).
*/

#include<stdio.h>

//Protótipo da função
int quantidadeLetras(char nomeArq[]);


void main(){
	char nomeArquivo[20];
	int quant;
	
	printf("Digite o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArquivo);
	
	quant = quantidadeLetras(nomeArquivo);
	
	if(quant == -1){
		printf("\nERROR na abertura do arquivo");
	}
	else{
		printf("\nExistem %d letras no arquivo %s", quant, nomeArquivo);
	}
}

int quantidadeLetras(char nomeArq[]){
	FILE *arq;
	char ch;
	int cont = 0;
	
	arq = fopen(nomeArq, "r");
	
	if(!arq){
		return -1;
	}
	else{
		
		while(fscanf(arq, "%c", &ch) != EOF){
			
			ch = toupper(ch);
			
			if((ch >= 'A') && (ch <= 'Z')){
				cont++;
			}
		}
		
		fclose(arq);
		
		return cont;
	}
}
