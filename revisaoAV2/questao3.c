/*
Desenvolver uma fun��o que remover um n�mero na i-�sima posi��o de uma lista
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


//Prot�tipos da fun��o
int inserir(TLista *L, int num);
int removerNaPosicao(TLista *L, int p);
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
	
	printf("\n\nEscolha a posicao que vai ser removida: ");
	scanf("%d", &pos);
	
	if(removerNaPosicao(&L, pos) == TRUE){
		
		exibir(L);
	}
	else{
		
		printf("[ERROR] numero nao inserido");
	}
}

int inserir(TLista *L, int num){
	
	TLista aux;
	
	//Passo 1: alocar mem�ria para o novo valor
	aux = malloc(sizeof(TNo));
	
	//Verificar se a mem�ria foi alocada
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da mem�ria rc�m-alocada
		aux->valor = num;
		
		//Passo 3: fazer com que o campo 'prox' da mem�ria rec�m-alocada
		//aponte para o "antigo" primeiro n� da lista
		aux->prox = *L;
		
		//Passo 4: Faz a lista apontar para o novo n�
		*L = aux;
		
		return TRUE;
	}
}

int removerNaPosicao(TLista *L, int p){
	
	TLista aux, remover;
	
	int cont = 1;
	
	if(p <= 0){
		
		return FALSE;
	}
	else
	{
		aux = *L;
		
		//andando com 'aux' at� o n� anterior � posi��o desejada (ou at� terminar a lista)
		while((cont < p-1) && (aux)){
			
			//atualizando 'aux'
			aux = aux->prox;
			
			//atualizando 'cont'
			cont++;
		}
		
		//testando se a posi��o dada � inv�lida
		if(!aux){
			
			return FALSE;
		}
		else{
			
			//alocando mem�ria para o novo n�
			remover = malloc(sizeof(TNo));
			
			//testando se houve erro na aloca��o
			if(!remover){
				
				return FALSE;
			}
			else{
				
				remover = aux->prox;
				
				aux->prox = remover->prox;
				
				//printf("\n\nRemover %d", remover->valor);
				//printf("\n\nAux %d", aux->valor);
				
				free(remover);
				
				return TRUE;
			}
		}
	}
}

void exibir(TLista L){
	
	TLista aux;
	
	printf ("\n\nLista: ");
	
	//fazendo 'aux' apontar para o primeiro n�
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
