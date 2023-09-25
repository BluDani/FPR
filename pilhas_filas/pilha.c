/*
	FAETERJ-Rio
	FPR - Manhã (21/06/2023)
	
	Pilhas (dinâmicas)
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
int empilhar(TLista *P, int numero);
int desempilhar(TLista *P, int *numero);
int topo(TLista P, int *t);

int menu ();

//main 
void main ()
{
	//declaração de variáveis
	TLista P = NULL;  //representando a pilha inicialmente vazia
	int numero, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch(op)
		{
			//Empilhar
			case 1: printf("\nEntre com o valor a ser empilhado: ");
			        scanf("%d", &numero);
			        
			        //chamando a função
			        if(empilhar (&P, numero) == TRUE){
			        	
			        	printf ("\n\tInsercao realizada com sucesso na pilha!\n");
					}
					else{
						
						printf ("\n\tERRO: insercao nao realizada na pilha!\n");
					}
					break;

			//Desempilhar
			case 2: //chamando a função
			        if(desempilhar(&P, &numero) == TRUE){
			        	
			        	printf ("\n\tO numero %d foi desempilhado\n", numero);
					}
					else{
						
						printf ("\n\tERRO: Pilha vazia!");
					}
					break;

			//Topo
			case 3: //chamando a função
			        if(topo (P, &numero) == TRUE){
			        	
			        	printf ("\n\tTopo da pilha: %d\n", numero);
					}
					else{
						
						printf ("\n\tERRO: Pilha vazia!");
					}
					break;
					
			//Saída
			case 4: printf("\n\nPrograma finalizado!");
			        break;
			        
			default: printf("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//implementação das funções

//inserindo no início da lista
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

int topo(TLista P, int *t){
	
	//verificando se a pilha está vazia
	if(!P){
		
		return FALSE;
	}
	else{
		
		*t = P->valor;
		
		return TRUE;
	}
}

int menu(){
	
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf("Menu de Operacoes:\n\n");
	printf("(1) Empilhar\n");
	printf("(2) Desempilhar\n");
	printf("(3) Topo\n");
	printf("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf("Entre com a sua opcao: ");
	scanf("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
