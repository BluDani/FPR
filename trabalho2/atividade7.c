/*
Pede-se a implementação de uma função
recursiva que, dada uma lista do tipo TLista,
ordenada crescentemente, determine a
quantidade de valores distintos na lista.

2 6 8 7 5
*/

#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct No{
	
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//Protótipo das funções
int inserir(TLista *L, int num);
void exibirLista(TLista L);
int distintos(TLista L);
void distintosRec(TLista L, TLista aux, int *cont);

void main(){
	TLista L = NULL;
	int num, res;
	
	do{
		printf("Digite um numero [-1 para parar]: ");
		scanf("%d", &num);
		
		if((num != -1) && (inserir(&L, num) == TRUE)){
			
			printf("Numero inserido\n\n");
		}
		else{
			
			printf("Numero nao inserido\n\n");
		}
	}
	while(num != -1);
	
	exibirLista(L);
	
	res = distintos(L);
	
	printf("\n\nTem %d numeros distintos na lista", res);
}

int inserir(TLista *L, int num){
	
	TLista aux;
	
	//Passo 1: alocar memória para o novo valor
	aux = malloc(sizeof(TNo));
	
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da memória recém-alocada
		aux->valor = num;
		
		//Passo 3: fazer com que o campo 'prox' da memória recém-alocada
		//aponte para o "antigo" primeiro nó da lista
		aux->prox = *L;
		
		//Passo 4: Faz a lista apontar para o novo nó
		*L = aux;
		
		return TRUE;
	}
}

void exibirLista(TLista L){
	
	TLista aux;
	
	printf("Lista: ");
	
	//fazendo 'aux' apontar para o primeiro nó
	aux = L;
	
	//percorrendo toda a lista
	//while (aux != NULL)
	while(aux){
		
		//Exibindo cada elemento da lista
		printf("%d ", aux->valor);
		
		//Atualizar o aux
		aux = aux->prox;
	}
}

int distintos(TLista L){
	
	TLista aux;
	int cont = 1;
	
	//faz o aux apontar pro prox apontado pelo L
	aux = L;
	
	distintosRec(aux, aux->prox, &cont);
	
	return cont;
}

void distintosRec(TLista L, TLista aux, int *cont){
	
	//Vai ficar executando até aux ser NULL
	if(aux){
		
		//verificando se o valor apontado pelo L é diferente do valor apontado pelo aux
		if(L->valor != aux->valor){
			
			(*cont)++;
			
		}
		
		distintosRec(L->prox, aux->prox, cont);
	}
}
