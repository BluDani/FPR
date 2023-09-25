/*
Quest�o 04 [2,5 pontos]:
Dadas duas pilhas P1 e P2, ambas do tipo TLista, desenvolver uma fun��o que determine quantos elementos de P1
tamb�m est�o em P2.
Notas:

1. Caso determinado valor apare�a mais de uma vez em P1, a solu��o final poder� cont�-lo tantas vezes
quantas forem as suas ocorr�ncias;

2. Caso alguma estrutura auxiliar seja necess�ria, esta ser� obrigatoriamente uma pilha ou uma fila;

3. A solu��o apresentada deve respeitar as regras de manipula��o de pilhas e/ou filas, em sua vers�o
cl�ssica.
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

//Prot�tipos da fun��o
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
	
	//declara��o de vari�veis
	TLista aux;
	
	//Passo 1: alocar mem�ria para o novo valor
	aux = malloc (sizeof(TNo));
	
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da mem�ria rec�m-alocada
		aux->valor = numero;
		
		//Passo 3: fazer com que o campo 'prox' da mem�ria rec�m-alocada
		//aponte para o "antigo" topo da pilha
		aux->prox = *P;
		
		//Passo 4: Faz a pilha apontar para o novo n�
		*P = aux;
		
		return TRUE;
	}

}


int desempilhar(TLista *P, int *numero){
	
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a pilha est� vazia
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
	
	//Tentei fazer as pilhas retornarem, mas n�o est� dando certo
	
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
