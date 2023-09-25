/*
Quest�o 03 [2,5 pontos]:
Implementar uma fun��o que, dada uma lista encadeada L, do tipo TLista, e um n�mero inteiro n, determine se todos
os valores inferiores ou iguais do que n est�o nos primeiros n�s de L, assim como os maiores ao final da lista.

Notas: caso todos os valores da lista sejam menores ou iguais a n, a fun��o dever� retornar 1; o mesmo aplica-
se quando todos os elementos forem maiores do que n.
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

//Prot�tipo da fun��o
int enfilar (TLista *L, TLista *U, int numero);
int verificandoLista(TLista L, TLista U, int num);
void exibirLista(TLista L);

void main(){
	
	TLista L = NULL, U = NULL;
	
	int num, valor, res;
	
	do{
		printf("Digite um numero [-1 para parar]: ");
		scanf("%d", &num);
		
		if((num != -1) && (enfilar(&L, &U, num) == TRUE)){
			
			printf("Numero inserido\n\n");
		}
		else{
			
			printf("Numero nao inserido\n\n");
		}
	}
	while(num != -1);
	
	exibirLista(L);
	
	printf("\n\nDigite um numero: ");
	scanf("%d", &valor);
	
	res = verificandoLista(L, U, valor);
	
	printf("%d", res);
}

int enfilar(TLista *L, TLista *U, int numero){
	
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
		
		//Passo 3: fazer o campo 'prox' do novo n� apontar para NULL
		aux->prox = NULL;
		
		//Passo 4: fazer o 'antigo �ltimo elemento' apontar para o novo n�
		if(*U){
			
			(*U)->prox = aux;
		}
		else{
			
			*L = aux;
		}
		
		//Passo 5: atualizar o ponteiro 'U'
		*U = aux;   //ou   *U = (*U)->prox;	

		return TRUE;
	}
}

int verificandoLista(TLista L, TLista U, int num){
	
	TLista aux;
	
	int maior = 0, menor = 0;
	
	aux = L;
	
	while(aux){
		
		if(aux->valor > num){
			
			maior++;
		}
		else{
			
			menor++;
		}
		
		
		aux = aux->prox;	
	}
	
	if(maior == 0){
		
		return 1;
	}
	
	if(menor == 0){
		return 1;
	}
	
	return 0;
}

void exibirLista(TLista L){
	
	TLista aux;
	
	printf("Lista: ");
	
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
