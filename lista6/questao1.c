/*
Quest�o 01:
Uma loja de autom�veis mant�m os carros �
venda sob a forma de um vetor de structs
contendo as seguintes informa��es, para cada
ve�culo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabrica��o (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declara��o de uma vari�vel que
represente o estoque de ve�culos da loja,
incluindo todas as declara��es de tipos que
possam ser necess�rias.
Al�m disso, implementar as seguintes fun��es:

i. Exibir todos os carros do modelo m, ano de
fabrica��o entre a1 e a2 (inclusive), com
valor n�o superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de 2.5%;
iii. Retirar do estoque um determinado ve�culo,
dada a sua placa.
*/

#include<stdio.h>

#define TAM 30
#define QUANT 2
typedef struct{
	
	char placa[TAM], modelo[TAM], marca[TAM], cor[TAM], tipo[TAM];
	float quilometragem, valor;
	
} TCarro;

//Prot�tipo da fun��o
void preencherStruct(TCarro carro[], int quant);
void exibirStruct(TCarro carro[], int quant);

void main(){
	TCarro carros[QUANT];
	
	preencherStruct(carros, QUANT);
	exibirStruct(carros, QUANT);
}

void preencherStruct(TCarro carro[], int quant){
	int i;
	
	for(i = 0; i < quant; i++){
		
		fflush(stdin);
		printf("\n\nPlaca do veiculo: ");
		gets(carro[i].placa);
		
		printf("Modelo do veiculo: ");
		gets(carro[i].modelo);
		
		printf("Marca do veiculo: ");
		gets(carro[i].marca);
		
		printf("Cor do veiculo: ");
		gets(carro[i].cor);
		
		printf("Quilometragem do veiculo: ");
		scanf("%f", &carro[i].quilometragem);
		
		if(carro[i].quilometragem == 0){
			carro[i].tipo == '0 km';
		}
		else{
			carro[i].tipo == 'usado';
		}
		
		printf("Valor do veiculo: ");
		scanf("%f", &carro[i].valor);
	}
}

void exibirStruct(TCarro carro[], int quant){
	int i;
	
	for(i = 0; i < quant; i++){
		
		printf("\n\n\nA placa do %d� veiculo e %s", i +1, carro[i].placa);
		printf("\nO modelo do %d� veiculo e %s", i +1, carro[i].modelo);
		printf("\nA marca do %d� veiculo e %s", i +1, carro[i].marca);
		printf("\nA cor do %d� veiculo e %s", i+1, carro[i].cor);
		printf("\nA quilometragem do %d� veiculo e %.2f", i +1, carro[i].quilometragem);
		printf("\nO tipo do %d� veiculo e %s", i +1, carro[i].tipo);
		printf("\nO valor do %d� veiculo e %.2f", i +1, carro[i].valor);
	}
}
