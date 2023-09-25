/*
Quest�o 02 [2,5 pontos]:
Implementar uma fun��o recursiva que, dada uma lista encadeada L, do tipo TLista, e um n�mero inteiro n, remova de L
todos os valores maiores do que n.
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
int removerNum(TLista *L, int num);
int removerNumRec(TLista *L, TLista aux, TLista remover, int num);
void exibir(TLista L);


void main(){
	
	TLista L = NULL;
	
	int valor, numRemover;
	
	do{
		printf("Digite um numero [-1 para parar]: ");
		scanf("%d", &valor);
		
		if((valor != -1) && (inserir(&L, valor) == TRUE)){
			
			printf("Numero inserido\n\n");
		}
		else{
			printf("Numero nao inserido");
		}
	}
	while(valor != -1);
	
	exibir(L); 
	
	printf("\n\nDigite um valor: ");
	scanf("%d", &numRemover);
	
	removerNum(&L, numRemover);
	
	exibir(L);
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

int removerNum(TLista *L, int num){
	
	TLista anterior, atual;
	
	removerNumRec(L, atual, anterior, num);
}

int removerNumRec(TLista *L, TLista atual, TLista anterior, int num){
	
	if(*L){
		
		
		//removendo as ocorr�ncias de 'numero' no in�cio da lista. 
		if(((*L)->valor > num))
		{
			atual = *L;
			*L = atual->prox;  //ou   *L = (*L)->prox;
			free (atual);
				
		}
		
		//verificando se a lista n�o est� vazia
		if (*L)
		{
			//colocando os ponteiros 'anterior' e 'atual' nas duas primeiras
			//posi��es da lista
			anterior = *L;
			atual = anterior->prox;
			
			if (atual)
			{
				
				if (atual->valor > num)
				{
					anterior->prox = atual->prox;
					free (atual);
					
					
					atual = anterior->prox;
				}
				else
				{
					//atualizando os ponteiros
					anterior = atual;
					atual = anterior->prox;
				}
			}
		}
		
		removerNumRec(&(*L)->prox, atual, anterior, num);
	}
	else{
		
		return FALSE;
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
