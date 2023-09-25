/*
	FAETERJ-Rio
	FPR - Manhã (21/06/2023)
	
	Filas (dinâmicas)
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);

int menu ();

//main 
void main(){
	
	//declaração de variáveis
	TLista F = NULL, U = NULL;  //representando a fila inicialmente vazia
	int numero, op;
	
	do
	{
		system("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu();
		
		//verificando a opção escolhida
		switch(op)
		{
			//Enfilar
			case 1: printf("\nEntre com o valor a ser enfilado: ");
			        scanf("%d", &numero);
			        
			        //chamando a função
			        if(enfilar(&F, &U, numero) == TRUE){
			        	
			        	printf("\n\tInsercao realizada com sucesso na fila!\n");
					}
					else{
						
						printf("\n\tERRO: insercao nao realizada na fila!\n");
					}
					break;

			//Desenfilar
			case 2: //chamando a função
			        if(desenfilar(&F, &U, &numero) == TRUE){
			        	
			        	printf("\n\tO numero %d foi desenfilado\n", numero);
					}
					else{
						
						printf("\n\tERRO: Fila vazia!");
					}
					break;

			//Primeiro
			case 3: //chamando a função
			        if(primeiro(F, &numero) == TRUE){
			        	
			        	printf("\n\tPrimeiro elemento da fila: %d\n", numero);
					}
					else{
						
						printf("\n\tERRO: Fila vazia!");
					}
					break;
					
			//Saída
			case 4: printf("\n\nPrograma finalizado!");
			        break;
			        
			default: printf("\n\nOpcao invalida! Tente novamente.");
		}
		
		system("PAUSE");
	}
	while(op != 4);
}

//implementação das funções

//inserindo no início da lista
int enfilar(TLista *F, TLista *U, int numero){
	
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
		
		//Passo 3: fazer o campo 'prox' do novo nó apontar para NULL
		aux->prox = NULL;
		
		//Passo 4: fazer o 'antigo último elemento' apontar para o novo nó
		if(*U){
			
			(*U)->prox = aux;
		}
		else{
			
			*F = aux;
		}
		
		//Passo 5: atualizar o ponteiro 'U'
		*U = aux;   //ou   *U = (*U)->prox;	

		return TRUE;
	}
}

int desenfilar(TLista *F, TLista *U, int *numero){
	
	TLista aux;
	
	//verificando se a fila está vazia
	//if (*F == NULL)
	if(!(*F)){
		
		return FALSE;
	}
	else{
		
		aux = *F;
		*F = aux->prox;		//ou   *F = (*F)->prox;
		
		//verificando se a fila se tornou nula. Ou seja,
		//foi removido o seu último elemento
		if(!(*F)){
			
			*U = NULL;
		}
		
		//salvando em 'numero' o valor que era o primeiro da fila
		*numero = aux->valor;
		
		free (aux);
		
		return TRUE;
	}
}

int primeiro(TLista F, int *p){
	
	//verificando se a fila está vazia
	if(!F){
		
		return FALSE;
	}
	else{
		
		*p = F->valor;
		
		return TRUE;
	}
}

int menu(){
	
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf("Menu de Operacoes:\n\n");
	printf("(1) Enfilar\n");
	printf("(2) Desenfilar\n");
	printf("(3) Primeiro\n");
	printf("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf("Entre com a sua opcao: ");
	scanf("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
