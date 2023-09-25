#include<stdio.h>
#include<stdlib.h>

//Defini��o de constantes
#define FALSE 0
#define TRUE 1

//Defini��o de tipos
typedef struct No{
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//Prot�tipos das fun��es
int menu();

int inserir(TLista *L, int numero);
int remover(TLista *L, int numero);
int alterar(TLista L, int num1, int num2);
TLista buscar(TLista L, int numero);
void exibir(TLista L);

void main(){
	
	//Declara��o de vari�veis
	TLista L = NULL;	//Representando a lista inicialmente vazia
	int num1, num2, op, quant;
	TLista resp;
	
	do{
		system ("CLS");		//limpar tela    clrscr();
		
		//Exibindo o menu ao usu�rio
		op = menu();
		
		//Verificando a op��o escolhida
		
		switch(op){
			
			//Inser��o
			case 1:
				printf ("\nEntre com o valor a ser inserido: ");
			    scanf ("%d", &num1);
			    
			    //Chamando a fun��o
			    if(inserir (&L, num1) == TRUE){
			    	
			    	printf ("\n\tInsercao realizada com sucesso!");
					}
					else{
						
						printf ("\n\tERRO: insercao nao realizada!");
					}
					
					break;
				
			//Remo��o
			case 2:
				printf ("\nEntre com o valor a ser removido: ");
			    scanf ("%d", &num1);
			        
			    //chamando a fun��o
			    quant = remover(&L, num1);
			    
			    if(quant > 0){
			    	
			    	printf ("\n\t%d remocoes realizadas!", quant);
				}
				else{
					
					printf ("\n\tERRO: remocao nao realizada!");
				}
				
				break;
				
			//Altera��o
			case 3:
				printf ("\nEntre com o valor a ser alterado: ");
			    scanf ("%d", &num1);
			        
			    printf ("\nEntre com o novo valor: ");
			    scanf ("%d", &num2);
			        
			    //chamando a fun��o
			    quant = alterar (L, num1, num2);
			    
			    if(quant > 0){
			    	
			    	printf ("\n\t%d alteracoes realizadas!", quant);
				}
				else{
					
					printf ("\n\tERRO: alteracao nao realizada!");
				}
				
				break;
				
			//Busca
			case 4:
				printf ("\nEntre com o valor a ser buscado: ");
			    scanf ("%d", &num1);
			        
			    //chamando a fun��o
			    resp = buscar (L, num1);
			    
			    if(resp != NULL){
			    	
			    	printf ("\n\tO valor %d foi encontrado na lista!", num1);
				}
				else{
					
					printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
				}
				
				break;
				
			//Exibir
			case 5:
				exibir(L);
				break;
				
			//Sa�da
			case 6:
				printf ("\n\nPrograma finalizado!");
			    break;
			    
			default:
				printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while(op != 6);
}

//Implementa��o das fun��es

int menu(){
	
	//Declara��o de vari�veis
	int opcao;
	
	//Exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//Lendo op��o do usu�rio
	printf("O que quer fazer: ");
	scanf("%d", &opcao);
	
	return opcao;
}

//Inserindo no in�cio da lista
int inserir(TLista *L, int numero){
	
	TLista aux;
	
	//Passo 1: alocar mem�ria para o novo valor
	aux = malloc(sizeof(TNo));
	
	//Verificar se a mem�ria foi alocada
	if(!aux){
		
		return FALSE;
	}
	else{
		
		//Passo 2: inserir o novo valor no campo 'valor' da mem�ria rc�m-alocada
		aux->valor = numero;
		
		//Passo 3: fazer com que o campo 'prox' da mem�ria rec�m-alocada
		//aponte para o "antigo" primeiro n� da lista
		aux->prox = *L;
		
		//Passo 4: Faz a lista apontar para o novo n�
		*L = aux;
		
		return TRUE;
	}
}

int remover(TLista *L, int numero){
	
	int quant = 0;
	TLista anterior, atual;
	
	//Removendo todas as ocorr�ncias de 'numero' no in�cio da lista.
	while((*L) && ((*L)->valor == numero)){
		
		atual = *L;
		*L = atual->prox;	//*L = (*L)->valor
		
		free(atual);
		
		//Atualizando a quantidade de remo��es
		quant++;
	}
	
	//Verificando se a lista n�o est� vazia
	
	if(*L){
		
		//colocando os ponteiros 'anterior' e 'atual' nas duas primeiras
		//posi��es da lista
		anterior = *L;
		atual = anterior->prox;
		
		//Percorrendo toda a lista
		//while (atual != NULL)
		while(atual){
			
			//Verificando se 'numero' foi encontrado
			if(atual->valor == numero){
				
				anterior->prox = atual->prox;
				free(atual);
				
				quant++;
				
				atual = anterior->prox;
			}
			else{
				
				//Atualizando os ponteiros
				anterior = atual;
				atual = anterior->prox;
			}
		}
	}
	
	//Retornar a quantidade de remo��es
	return quant;
}

int alterar(TLista L, int num1, int num2){
	
	TLista aux;
	int quant = 0;
	
	//Fazendo 'aux' apontar para o primeiro n�
	aux = L;
	
	//Percorrendo toda a lista
	
	while(aux){
		
		//Verificando se o n�mero a ser alterado foi encontrado
		if(aux->valor == num1){
			
			aux->valor = num2;
			
			quant++;
		}
		
		//Atualizar o aux
		aux = aux->prox;
	}
	
	//Retornando a quantidade de altera��es realizadas
	return quant;
}

TLista buscar(TLista L, int numero){
	
	TLista aux;
	
	//Fazendo 'aux' apontar para o primeiro n�
	aux = L;
	
	//Percorrendo toda a lista
	while(aux){
		
		//Verificando se 'numero' foi encontrado
		if(aux->valor == numero){
			
			return aux;
		}
		
		//Atualizar o aux
		aux = aux->prox;
	}
	
	return NULL;
}

void exibir(TLista L){
	
	TLista aux;
	
	//Verificando se a lista est� vazia
	//if (L == NULL)
	if(!L){
		
		printf("\n\nLista vazia!\n");
	}
	else{
		
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
}
