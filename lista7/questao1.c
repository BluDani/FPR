/*
Questão 01:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.
*/

#include<stdio.h>

//Protótipo da função
int numeroCaracter(char nomeArq[]);


void main(){
	char nomeArquivo[20];
	int quant;
	
	printf("Escreva o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArquivo);
	
	quant = numeroCaracter(nomeArquivo);
	
	if(quant == -1){
		printf("\nErro na abertura do arquivo");
	}
	else{
		printf("\nForam encontrados %d caracteres no arquivo %s", quant, nomeArquivo);
	}
}

int numeroCaracter(char nomeArq[]){
	FILE *arq;
	char caracter;
	int cont = 0;
	
	//abrindo arquivos
	arq = fopen(nomeArq, "r");
	
	//Verificando se houve erro na abertura
	//if(arq != NULL)
	if(!arq){
		return -1;
	}
	else{
		
		//Lendo todos os caracteres do arquivo
		while(fscanf(arq, "%c", &caracter) != EOF){
			
			cont++;
		}
		
		//Fechando arquivo
		fclose(arq);
		
		return cont;
	}
}
