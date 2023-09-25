/*
Desenvolver uma função que insira um número inteiro N na i-ésima posição de uma lista
encadeada L.
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


//Protótipos da função
int inserir(TLista *L, int num);
int inserirNaPosicao(TLista *L, int p, int num);
void exibir(TLista L);

void main(){
	
	TLista L = NULL;
	
	int num, pos;
	
		do{
		printf("Digite um numero [-1 para parar]: ");
		scanf("%d", &num);
		
		if((num != -1) && (inserir(&L, num) == TRUE)){
			
			printf("Numero inserido\n\n");
		}
		else{
			printf("Numero nao inserido");
		}
	}
	while(num != -1);
	
	exibir(L);
	
	printf("\n\nEscolha uma posicao: ");
	scanf("%d", &pos);
	
	printf("\nEscolha um numero para inserir: ");
	scanf("%d", &num);
	
	if(inserirNaPosicao(&L, pos, num) == TRUE){
		
		exibir(L);
	}
	else{
		
		printf("[ERROR] numero nao inserido");
	}
}

int inserir(TLista *L, int num){
	
	TLista aux;
	
	//Passo 1: alocar memória para o novo valor
	aux = malloc(sizeof(TNo));
	
	//Verificar se a memória foi alocada
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da memória rcém-alocada
		aux->valor = num;
		
		//Passo 3: fazer com que o campo 'prox' da memória recém-alocada
		//aponte para o "antigo" primeiro nó da lista
		aux->prox = *L;
		
		//Passo 4: Faz a lista apontar para o novo nó
		*L = aux;
		
		return TRUE;
	}
}

int inserirNaPosicao(TLista *L, int p, int num){
	
	TLista aux, novo;
	
	int cont = 1;
	
	if(p <= 0){
		
		return FALSE;
	}
	else
	{
		aux = *L;
		
		//andando com 'aux' até o nó anterior à posição desejada (ou até terminar a lista)
		while((cont < p-1) && (aux)){
			
			//atualizando 'aux'
			aux = aux->prox;
			
			//atualizando 'cont'
			cont++;
		}
		
		//testando se a posição dada é inválida
		if(!aux){
			
			return FALSE;
		}
		else{
			
			//alocando memória para o novo nó
			novo = (TLista)	malloc (sizeof(TNo));
			
			//testando se houve erro na alocação
			if(!novo){
				
				return FALSE;
			}
			else{
				
				//armazenando 'numero' no novo nó
				novo->valor = num;
				
				if(p > 1){
					
					//fazer o novo nó apontar para o próximo
					novo->prox = aux->prox;
					
					//fazer o nó anterior apontar para o novo
					aux->prox = novo;
				}
				else{
					
					//inserção no início da lista
					
					//fazendo o novo nó apontar para o primeiro elemento da lista
					novo->prox = *L;
					
					//atualizando L para apontar para o primeiro nó
					*L = novo;
				}
				
				return TRUE;
			}
		}
	}
}

void exibir(TLista L){
	
	TLista aux;
	
	printf ("\n\nLista: ");
	
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
