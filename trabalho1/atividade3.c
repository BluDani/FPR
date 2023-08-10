/*
Uma Clínica Veterinária mantém um vetor de
structs, do qual cada posição armazena as
seguintes informações: código do cadastro,
nome do pet, nome do tutor, e-mail de contato,
data da última vacina.
Desenvolver uma função que, dado um vetor
com esta estrutura, gere um arquivo texto com
os dados dos pets com vacina vencida (mais de
um ano da última).
Cada linha do arquivo terá a seguinte sintaxe:

email|mensagem

E a mensagem terá o formato apresentado
abaixo:
Prezado <nome_tutor>, a vacina do pet
<nome_pet> venceu no dia dd/mm/aaaa.
Podemos agendar a nova dose?

15 03 2020
17 07 2021
*/

#include<stdio.h>
#include<string.h>

typedef struct{
	int dia, mes, ano;
	
} TData;

typedef struct{
	int codigo;
	char nomePet[20];
	char nomeTutor[20];
	char email[50];
	TData vacina;
	
}TVeterinaria;

#define ANO 2023
#define MES 5
#define DIA 19

#define TAM 2

//Protótipo da função
void preencherStruct(TVeterinaria info[], int quant);
void exibirStruct(TVeterinaria info[], int quant);
int gerarArquivo(char nomeArq[], TVeterinaria info[], int quant, int ano, int mes, int dia);

void main(){
	TVeterinaria informacoes[TAM];
	char nomeArquivo[20];
	int res;
	
	strcpy(nomeArquivo, "teste.txt");
	
	preencherStruct(informacoes, TAM);
	exibirStruct(informacoes, TAM);
	
	res = gerarArquivo(nomeArquivo, informacoes, TAM, ANO, MES, DIA);
	
	if(res == 0){
		printf("\n\n[ERROR] Não foi possivel abrir o arquivo");
	}
	else{
		printf("\n\nArquivo criado com sucesso");
	}
}

void preencherStruct(TVeterinaria info[], int quant){
	int i;
	
	for(i = 0; i < quant; i++){
		
		printf("\n---------------------------------------");
		printf("\nCodigo do cadastro: ");
		scanf("%d", &info[i].codigo);
		
		printf("Nome do Pet: ");
		fflush(stdin);
		gets(info[i].nomePet);
		
		printf("Nome do Tutor: ");
		fflush(stdin);
		gets(info[i].nomeTutor);
		
		printf("Email: ");
		fflush(stdin);
		gets(info[i].email);
		
		printf("Data da ultima vacina (DD MM AA): ");
		scanf("%d %d %d", &info[i].vacina.dia, &info[i].vacina.mes, &info[i].vacina.ano);
	}
}

void exibirStruct(TVeterinaria info[], int quant){
	int i;
	
	for(i = 0; i < quant; i++){
		
		printf("\n\n==========================================");
		printf("\nCodigo de cadastro: %d", info[i].codigo);
		printf("\nNome do Pet: %s", info[i].nomePet);
		printf("\nNome do Tutor: %s", info[i].nomeTutor);
		printf("\nEmail: %s", info[i].email);
		printf("\nData da ultima vacina: %d/%d/%d", info[i].vacina.dia, info[i].vacina.mes, info[i].vacina.ano);
	}
}

int gerarArquivo(char nomeArq[], TVeterinaria info[], int quant, int ano, int mes, int dia){
	FILE *arq;
	int i, soma;
	
	//Abrindo arquivo
	arq = fopen(nomeArq, "w");
	
	//verificando se houve error na abertura
	if(!arq){
		
		return 0;
	}
	else{
		
		for(i = 0; i < quant; i++){
			
			//Inicializando soma
			soma = 0;
			
			//somando mês e o ano da vacina e diminuindo com o mês e ano atual
			soma = info[i].vacina.mes + info[i].vacina.ano - mes - ano;
			
			if(soma == -1){
				
				//verificando se o dia da vacina é menor ou igual ao dia atual
				if(info[i].vacina.dia <= dia){
					
					fprintf(arq, "%s / Prezado %s, a vacina do pet %s venceu no dia %d/%d/%d. Podemos agendar a nova dose?", 
							info[i].email, info[i].nomeTutor, info[i].nomePet, info[i].vacina.dia, info[i].vacina.mes, info[i].vacina.ano + 1);
						
					fprintf(arq, "\n");
				}
			}
			else{
				
				if(soma <= -2){
					
					fprintf(arq, "%s / Prezado %s, a vacina do pet %s venceu no dia %d/%d/%d. Podemos agendar a nova dose?", 
							info[i].email, info[i].nomeTutor, info[i].nomePet, info[i].vacina.dia, info[i].vacina.mes, info[i].vacina.ano + 1);
							
					fprintf(arq, "\n");
					
				}
			}
		}
		
		//fechando arquivo
		fclose(arq);
		
		return 1;
	}
}
