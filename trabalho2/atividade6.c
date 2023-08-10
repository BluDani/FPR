/*
Implementar uma função que, dada uma lista L1
do tipo TLista, crie uma nova lista, L2 (de tipo
diferente de TLista), contendo, em cada nó, um
elemento de L1 e a quantidade de vezes que
este aparece em L1.
Exemplo:

Elementos de L1: 1 4 5 7 4 3 2 5 4 7 1 2

A lista L2 conterá os seguintes nós:
• Um nó contendo o valor 1 e a
quantidade 2 (pois o número 1
aparece 2 vezes em L1);
• Um nó contendo o valor 4 e a
quantidade 3;
• Um nó contendo o valor 5 e a
quantidade 2;
• Um nó contendo o valor 7 e a
quantidade 2;
• Um nó contendo o valor 3 e a
quantidade 1;
• Um nó contendo o valor 2 e a
quantidade 2.
*/

#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

//Lista 1
typedef struct No1{
	
	int valor;
	struct No1* prox;
} TNo1;

typedef TNo1* TLista1;

//Lista 2
typedef struct No2{
	
	int valor;
	int quant;
	struct No2* prox;
} TNo2;

typedef TNo2* TLista2;

//Protótipo das funções
int inserir(TLista1* L1, int num);
int buscar(TLista1 L1, int num);
int repeticao(TLista2 L2, int num);
int criarLista2(TLista1 L1, TLista2* L2);
int inserirLista2(TLista2* L2, int num, int quant);
void exibirLista1(TLista1 L1);
void exibirLista2(TLista2 L2);

void main(){
	TLista1 L1 = NULL;
	TLista2 L2 = NULL;
	
	int num, lista2;
	
	do{
		printf("Digite um numero [-1 para parar]: ");
		scanf("%d", &num);
		
		if((num != -1) && (inserir(&L1, num) == TRUE)){
			
			printf("Numero inserido\n\n");
		}
		else{
			printf("Numero nao inserido");
		}
	}
	while(num != -1);
	
	if(L1){
		
		exibirLista1(L1);
	}
	
	lista2 = criarLista2(L1, &L2);
	
	if(lista2 == TRUE){
		
		exibirLista2(L2);
	}
	else{
		printf("\n\n[ERROR] Nao foi possivel criar lista");
	}
}

int inserir(TLista1* L1, int num){
	
	TLista1 aux;
	
	//Passo 1: alocar memória para o novo valor
	aux = malloc(sizeof(TNo1));
	
	//Verificar se a memória foi alocada
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da memória rcém-alocada
		aux->valor = num;
		
		//Passo 3: fazer com que o campo 'prox' da memória recém-alocada
		//aponte para o "antigo" primeiro nó da lista
		aux->prox = *L1;
		
		//Passo 4: Faz a lista apontar para o novo nó
		*L1 = aux;
		
		return TRUE;
	}
}

int buscar(TLista1 L1, int num){
	
	TLista1 aux;
	int cont = 0;
	
	//Fazendo 'aux' apontar para o primeiro nó
	aux = L1;
	
	while(aux){
		
		//verificando se o valor apontado pelo aux é igual a num
		if(aux->valor == num){
			
			cont++;
		}
		
		//Atualizar o aux
		aux = aux->prox;
	}
	
	return cont;
}

int repeticao(TLista2 L2, int num){
	
	TLista2 aux;
	
	//Fazendo 'aux' apontar para o primeiro nó
	aux = L2;
	
	while(aux){
		
		//verificando se o valor apontado pelo aux é igual a num
		if(aux->valor == num){
			
			return 0;
		}
		
		//Atualizar o aux
		aux = aux->prox;
	}
	
	return 1;
}

int criarLista2(TLista1 L1, TLista2* L2){
	
	TLista1 aux1;
	
	int repet, quant;
	
	//Fazendo 'aux' apontar para o primeiro nó
	aux1 = L1;
	
	if(!aux1){
		
		return FALSE;
	}
	else{
		
		while(aux1){
			
			//verificando se o valor da lista 1 já está inserido na lista 2
			repet = repeticao(*L2, aux1->valor);
			
			//se o valor da lista 1 não estiver, ele ira chamar a função buscar
			if(repet == 1){
				
				//verificando quantas vezes o valor aparece na lista 1
				quant = buscar(aux1, aux1->valor);
				
				//inserindo na lista 2 o valor e quantidade de vezes que o número aparece na lista 1
				inserirLista2(L2, aux1->valor, quant);
				
			}
			
			//Atualizar o aux
			aux1 = aux1->prox;
		}
		
		
		return TRUE;
	}
}

int inserirLista2(TLista2* L2, int num, int quant){
	
	TLista2 aux;
	
	//Passo 1: alocar memória para o novo valor
	aux = malloc(sizeof(TNo2));
	
	//Verificar se a memória foi alocada
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da memória rcém-alocada
		aux->valor = num;
		aux->quant = quant;
		
		//Passo 3: fazer com que o campo 'prox' da memória recém-alocada
		//aponte para o "antigo" primeiro nó da lista
		aux->prox = *L2;
		
		//Passo 4: Faz a lista apontar para o novo nó
		*L2 = aux;
		
		return TRUE;
	}
}

void exibirLista1(TLista1 L1){
	
	TLista1 aux;
	
	printf ("\n\nLista1: ");	

	//fazendo 'aux' apontar para o primeiro nó
	aux = L1;
	
	//percorrendo toda a lista
	//while (aux != NULL)
	while(aux){
		
		//Exibindo cada elemento da lista
		printf("%d ", aux->valor);
		
		//Atualizar o aux
		aux = aux->prox;
	}
}

void exibirLista2(TLista2 L2){
	
	TLista2 aux;
	
	printf ("\n\nLista2: ");	

	//fazendo 'aux' apontar para o primeiro nó
	aux = L2;
	
	//percorrendo toda a lista
	//while (aux != NULL)
	while(aux){
		
		//Exibindo cada elemento da lista
		printf("\n\nvalor:%d quant: %d", aux->valor, aux->quant);
		
		//Atualizar o aux
		aux = aux->prox;
	}
}
