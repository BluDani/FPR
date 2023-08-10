/*
Questão 01:
Considere um vetor que armazene alguns dados
coletados de um grupo de pessoas em uma
pesquisa, a saber: nome, gênero, idade e altura.

Desenvolver uma função que receba os
parâmetros gênero, faixa de idade (idade inicial
e idade final) e faixa de altura (altura inferior e
altura superior) e retorne a quantidade de
pessoas que atendem aos filtros por ele
representados.

Nota: caso o gênero especificado seja igual a M,
serão considerados os homens que estiverem
nas faixas de idade e altura especificadas; o
mesmo ocorrerá com as mulheres, quando o
gênero for F. Porém, se o gênero contiver
qualquer valor diferente de M ou F, todas as
pessoas que atenderem aos filtros de idade e
altura serão contabilizadas.

(p[i].idade >= idaI) && (p[i].idade <= idaF) && (p[i].altura >= altI) && (p[i].altura <= altF)
*/

#include<stdio.h>

#define TAM 2

typedef struct{
	char nome[50];
	char genero;
	int idade;
	float altura;
} TGrupo;

//Protótipo da função
void preencherStruct(TGrupo p[], int quant);
void exibirStruct(TGrupo p[], int quant);
int quantidadePessoas(TGrupo p[], int quant, char g, int idaI, int idaF, float altI, float altF);

void main(){
	TGrupo pessoas[TAM];
	char genero;
	int idadeI, idadeF, resultado;
	float alturaI, alturaF;
	
	preencherStruct(pessoas, TAM);
	
	exibirStruct(pessoas, TAM);
	
	printf("\n\nDigite o genero: ");
	fflush(stdin);
	scanf("%c", &genero);
	genero = toupper(genero);
	
	printf("Digite a idade inicial: ");
	scanf("%d", &idadeI);
	
	printf("Digite a idade final: ");
	scanf("%d", &idadeF);
	
	printf("Digite a altura inicial: ");
	scanf("%f", &alturaI);
	
	printf("Digite a altura final: ");
	scanf("%f", &alturaF);
	
	resultado = quantidadePessoas(pessoas, TAM, genero, idadeI, idadeF, alturaI, alturaF);
	
	printf("\nO total de pessoas do genero %c que tem a idade entre %d e %d e a altura entre %.2f %.2f e: %d"
	, genero, idadeI, idadeF, alturaI, alturaF, resultado);
}

void preencherStruct(TGrupo p[], int quant){
	int i;
	
	for(i = 0; i < quant; i++){
		printf("-------------------------------");
		
		printf("\nNome: ");
		fflush(stdin);
		gets(p[i].nome);
		
		printf("Genero: ");
		fflush(stdin);
		scanf("%c", &p[i].genero);
		p[i].genero = toupper(p[i].genero);
		
		printf("Idade: ");
		scanf("%d", &p[i].idade);
		
		printf("Altura: ");
		scanf("%f", &p[i].altura);
	}
}

void exibirStruct(TGrupo p[], int quant){
	int i;
	
	for(i = 0; i < quant; i++){
		printf("\n\n===============================");
		
		printf("\nNome: %s", p[i].nome);
		printf("\nGenero: %c", p[i].genero);
		printf("\nIdade: %d anos", p[i].idade);
		printf("\nAltura: %.2f cm", p[i].altura);
	}
}

int quantidadePessoas(TGrupo p[], int quant, char g, int idaI, int idaF, float altI, float altF){
	int i, cont = 0;
	
	for(i = 0; i < quant; i++){
		
		if((idaI >= p[i].idade <= idaF) && (altI >= p[i].altura <= altF)){
			
			if((g == 'M') || (g == 'F')){
				
				if(p[i].genero == g){
					cont++;
				}
			}
			else{
				cont++;
			}
			
		}
	}
	
	return cont;
}
