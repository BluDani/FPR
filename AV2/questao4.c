/*
Questão 04 [2,5 pontos]:
Dadas duas pilhas P1 e P2, ambas do tipo TLista, desenvolver uma função que determine quantos elementos de P1
também estão em P2.
Notas:

1. Caso determinado valor apareça mais de uma vez em P1, a solução final poderá contá-lo tantas vezes
quantas forem as suas ocorrências;

2. Caso alguma estrutura auxiliar seja necessária, esta será obrigatoriamente uma pilha ou uma fila;

3. A solução apresentada deve respeitar as regras de manipulação de pilhas e/ou filas, em sua versão
clássica.
*/

#include<stdio.h>
#include<stdlib.h>


#define FALSE 1
#define TRUE 0

typedef struct No{
	
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//Protótipos da função
int empilhar(TLista *P, int numero);
int desempilhar(TLista *P, int *numero);
int quantElementos(TLista *P1, TLista *P2);
void exibir(TLista P);

void main(){
	
	TLista P1 = NULL, P2 = NULL;
	
	int res;
	
	empilhar(&P1, 10);
	empilhar(&P1, 12);
	empilhar(&P1, 15);
	empilhar(&P1, 17);
	empilhar(&P1, 19);
	
	empilhar(&P2, 18);
	empilhar(&P2, 11);
	empilhar(&P2, 10);
	empilhar(&P2, 19);
	empilhar(&P2, 12);
	
	exibir(P1);
	
	res = quantElementos(&P1, &P2);
	
	printf("\n\nExistem %d elementos de P1 em P2", res);
	
	exibir(P1);
	exibir(P2);
	
}

int empilhar(TLista *P, int numero){
	
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória para o novo valor
	aux = malloc (sizeof(TNo));
	
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da memória recém-alocada
		aux->valor = numero;
		
		//Passo 3: fazer com que o campo 'prox' da memória recém-alocada
		//aponte para o "antigo" topo da pilha
		aux->prox = *P;
		
		//Passo 4: Faz a pilha apontar para o novo nó
		*P = aux;
		
		return TRUE;
	}

}


int desempilhar(TLista *P, int *numero){
	
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha está vazia
	//if(*P == NULL)
	if(!(*P)){
		
		return FALSE;
	}
	else{
		
		aux = *P;
		*P = aux->prox; //ou   *P = (*P)->prox;
		
		//salvando em 'numero' o valor que estava no topo
		*numero = aux->valor;
		
		free(aux);
		
		return TRUE;
	}
}

int quantElementos(TLista *P1, TLista *P2){
	
	TLista aux1, aux2;
	
	int removido1, removido2, quant = 0;
	
	while(desempilhar(P1, &removido1) == TRUE){
		
		if(*P2){
			
			while(desempilhar(P2, &removido2) == TRUE){
				
				
				if(removido1 == removido2){
					
					quant++;
				}
				
				empilhar(&aux2, removido2);
				
			}
			
		}
		else{
			
			while(desempilhar(&aux2, &removido2) == TRUE){
				
				if(removido1 == removido2){
					
					quant++;
				}
				
				empilhar(P2, removido2);
			}
			
		}
		
		
		empilhar(&aux1, removido1);
	}
	
	//Tentei fazer as pilhas retornarem, mas não está dando certo
	
	/*
	if(aux2){
		
		while(desempilhar(&aux2, &removido2) == TRUE){
			
			empilhar(P2, removido2);
		}
	}
	*/
	/*
	while(desempilhar(&aux1, &removido1) == TRUE){
		
		empilhar(P1, removido1);
	}
	*/
	
	return quant;
}

void exibir(TLista P){
	
	TLista aux;
	
	if(!aux){
		
		printf("\n\nFila vazia");
	}
	else{
		
		printf ("\n\nFila: ");	
		
		aux = P;
		
		while(aux){
			
			printf("%d ", aux->valor);
			
			aux = aux->prox;
		}
	}
}
