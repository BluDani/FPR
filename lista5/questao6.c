/*
QUESTÃO 06:
Considere uma loja que mantém em uma
matriz o total vendido por cada funcionário
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mês) e 10 colunas
(10 funcionários). Pede-se o desenvolvimento
de uma função para cada item abaixo:

a. Calcular o total vendido durante o ano;
b. Dado um mês fornecido pelo usuário,
determinar o total vendido nesse mês;
c. Dado um funcionário fornecido pelo
usuário, determinar o total vendido por ele
durante o ano;
d. Determinar o mês com maior índice de
vendas;
e. Determinar o funcionário que menos
vendeu durante o ano.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MESES 12
#define FUNC 10

//Protótipo da função



void main(){
	float matriz[MESES][FUNC];
	
	
}

float totalVendas(float m[MESES][FUNC]){
	int i, j;
	float total = 0;
	
	for(i = 0; i < MESES; i++){
		
		for(j = 0; j < FUNC; j++){
			
			total += m[MESES][FUNC];
		}
	}
	
	return total;
}

float totalVendasMes(float m[MESES][FUNC], int mes){
	int j;
	float soma = 0;
	mes--; //convertendo de 1 a 12 para 0 a 11 (c)
	
	for(j = 0; j < FUNC; j++){
		soma += m[mes][j];
	}
	
	return soma;
}

float totalVendasFuncionario(float m[MESES][FUNC], int func){
	int i;
	float soma = 0;
	func--;
	
	for(i = 0; i < MESES; i++){
		
		soma += m[i][func];
	}
	
	return soma;
}

float mesMaiorVendas(float m[MESES][FUNC]){
	float maior = totalVendasMes(m, 0), total;
	int mes = 0, i;
	
	for(i = 1; i < MESES; i++){
		
		total = totalVendasMes(m, i);
		
		if(total > maior){
			maior = total;
			mes= i;
			
		}
	}
	
	return mes + 1;
}

float funcionarioMenosVendas(float m[MESES][FUNC]){
	float menor = totalVendasFuncionario(m, 0);
	int func = 0, i, j;
	
	
}
