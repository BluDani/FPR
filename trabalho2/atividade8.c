/*
Fazer uma fun��o que, dada uma Fila F, do tipo
TLista, e dois valores inteiros num1 e num2,
remova da fila todos os valores pertencentes ao
intervalo definido por num1 e num2, inclusive.

Nota: para a solu��o desta atividade,
considerar a implementa��o cl�ssica de filas!
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

//Prot�tipos das fun��es
int enfilar(TLista *F, TLista *U, int num);
int desenfilar(TLista *F, TLista *U, int *num);
int removerIntervalo(TLista *F, TLista *U, int num1, int num2);
void exibir(TLista F);

void main(){
	
	TLista F = NULL, U = NULL;
	int numero, inicio, fim;
	int res;
	
	do{
		printf("Digite o valor a ser enfilado [-1 para parar]: ");
		scanf("%d", &numero);
		
		if(numero != -1){
			
			if(enfilar(&F, &U, numero) == TRUE){
				
				printf("Insercao realizada\n\n");
			}
		}
	}
	while(numero != -1);
	
	exibir(F);
	
	printf("\n\nDigite o inicio do intervalo: ");
	scanf("%d", &inicio);
	
	printf("Digite o fim do intervalo: ");
	scanf("%d", &fim);

	
	if(removerIntervalo(&F, &U, inicio, fim) == TRUE){
		
		printf("\n\nRemocao realizada");
		
		exibir(F);
	}
	else{
		
		printf("\n\nRemocao nao realizada");
	}
	
}

int enfilar(TLista *F, TLista *U, int num){
	
	TLista aux;
	
	//Passo 1: alocar mem�ria para o novo valor
	aux = malloc(sizeof(TNo));
	
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da mem�ria rec�m-alocada
		aux->valor = num;
		
		//Passo 3: fazer o campo 'prox' do novo n� apontar para NULL
		aux->prox = NULL;
		
		///Passo 4: fazer o 'antigo �ltimo elemento' apontar para o novo n�
		if(*U){
			
			(*U)->prox = aux;
		}
		else{
			
			*F = aux;
		}
		
		//Passo 5: atualizar o ponteiro 'U'
		*U = aux;	//ou   *U = (*U)->prox;
		
		return TRUE;
	}
}

int desenfilar(TLista *F, TLista *U, int *num){
	
	TLista aux;
	
	//verificando se a fila est� vazia
	//if (*F == NULL)
	if(!(*F)){
		
		return FALSE;
	}
	else{
		
		aux = *F;
		*F = aux->prox;
		
		//verificando se a fila se tornou nula. Ou seja,
		//foi removido o seu �ltimo elemento
		if(!(*F)){
			
			*U = NULL;
		}
		
		//salvando em 'numero' o valor que era o primeiro da fila
		*num = aux->valor;
		
		free(aux);
		
		return TRUE;
	}
}

int removerIntervalo(TLista *F, TLista *U, int num1, int num2){
	
	TLista F2 = NULL, U2 = NULL;
	
	int maior, menor;
	int removido;
	
	//verificando se a fila est� vazia
	//if (*F == NULL)
	if(!(*F)){
		
		return FALSE;
	}
	else{
		
		//verificando qual numero � maior e menor
		if(num1 > num2){
			
			maior = num1;
			menor = num2;
		}
		else{
			
			maior = num2;
			menor = num1;
		}
		
		//Desenfilando at� a fila ficar vazia
		while(desenfilar(F, U, &removido) == TRUE){
			
			//verificando se o n�mero removido n�o est� no intervalo
			if((removido < menor) || (removido > maior)){
					
				//Se n�o estiver no intervalo, ele ir� ser enfilado na lista auxiliar
				enfilar(&F2, &U2, removido);
			}
			
		}
		
		//Por �ltimo, todos os valores da fila 2 ser�o desenfilados e enfileirados de volta a lista principal
		while(desenfilar(&F2, &U2, &removido) == TRUE){
			
			enfilar(F, U, removido);
		}
		
		return TRUE;
	}
}

void exibir(TLista F){
	
	TLista aux;
	
	if(!aux){
		
		printf("\n\nFila vazia");
	}
	else{
		
		printf ("\n\nFila: ");	
		
		aux = F;
		
		while(aux){
			
			printf("%d ", aux->valor);
			
			aux = aux->prox;
		}
	}
}
