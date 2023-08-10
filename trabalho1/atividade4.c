/*
Implementar uma função que, dado um
arquivo texto A contendo números inteiros, um
por linha, cria um novo arquivo texto, B,
contendo os mesmos valores de A, porém em
ordem inversa.

Exemplo:

A		B

1		2
5		4
7		9
1		5
4		4
5		1
9		7
4		5
2		1

*/

#include<stdio.h>
#include<string.h>

//Protótipo da função
int arquivoInverso(char arquiA[], char arquiB[], char arquiAuxi[]);
int buscarUltimo(char arqAuxiliar[], int cont);

void main(){
	char arquivoA[20], arquivoB[20], arquivoAuxiliar[20];
	int res;
	
	strcpy(arquivoA, "arquivoA.txt");
	strcpy(arquivoB, "arquivoB.txt");
	strcpy(arquivoAuxiliar, "arquivoAuxiliar.txt");
	
	res = arquivoInverso(arquivoA, arquivoB, arquivoAuxiliar);
	
	if(res == 0){
		
		printf("[ERROR] na abertura do arquivo");
	}
	else{
		
		printf("Arquivo criado com sucesso!");
	}
	
}

int arquivoInverso(char arquiA[], char arquiB[], char arquiAuxi[]){
	FILE *arqA, *arqB, *arqAuxi;
	int res, valor, cont = 0;
	
	//abrindo arquivos
	arqA = fopen(arquiA, "r");
	arqB = fopen(arquiB, "w");
	arqAuxi = fopen(arquiAuxi, "w");
	
	//verificando se houve erro na abertura
	if((!arqA) || (!arqB) || (!arqAuxi)){
		
		return 0;
	}
	else{
		
		//descobrindo a quantidade de numeros no arquivo e criando arquivo auxiliar
		while(fscanf(arqA, "%d", &valor) != EOF){
			fprintf(arqAuxi, "%d", valor);
			fprintf(arqAuxi, "\n");
			
			cont++;
		}
		
		//fechando arquivo auxiliar e colocando o ponteiro do arquivoA para a primeira linha
		fclose(arqAuxi);
		rewind(arqA);
		
		while(fscanf(arqA, "%d", &valor) != EOF){
			
			//chamando função
			res = buscarUltimo(arquiAuxi, cont);
			
			if(res != 0){
				
				//copiando valor para arquivoB
				fprintf(arqB, "%d", res);
				fprintf(arqB, "\n");
				
				cont--;
				
			}
			
		}
	}
	
	//fechando arquivoA e excluindo arquivo auxiliar
	fclose(arqA);
	remove(arquiAuxi);
	
	return 1;
}

int buscarUltimo(char arqAuxiliar[], int cont){
	FILE *arq;
	int num, i;
	
	//abrindo arquivo para leitura
	arq = fopen(arqAuxiliar, "r");

	if(!arq){
		
		return 0;
	}
	else{
		
		//lendo valores até ser menor que cont
		for(i = 0; i < cont; i++){
			fscanf(arq, "%d", &num);
			
		}
		
		//fechando arquivo
		fclose(arq);
		
	}
	
	//retornando último valor
	return num;
}
