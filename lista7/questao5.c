/*
Questão 05:
	Faça uma função que, dado um arquivo A contendo números reais, 
	um por linha, crie um novo arquivo B contendo os mesmos elementos 
	de A, porém ordenados decrescentemente e sem repetição.
*/

//importação de bibliotecas
#include <stdio.h>
#include <float.h>

//protótipos das funções
int criarArquivoOrdenado (char nomeArqA[], char nomeArqB[]);
int buscarMaiorElemento (char nomeArq[], float limite, float *maior);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivoA[20], nomeArquivoB[20];
	int resultado;
	
	//lendo o nome do arquivo A
	printf ("Entre com o nome do arquivo original: ");
	fflush (stdin);
	gets (nomeArquivoA);

	//lendo o nome do arquivo B
	printf ("Entre com o nome do novo arquivo: ");
	fflush (stdin);
	gets (nomeArquivoB);	
	
	//chamando a função
	resultado = criarArquivoOrdenado (nomeArquivoA, nomeArquivoB);
	
	//verificando o restorno
	if (resultado == 0)
	{
		printf ("\nErro na abertura dos arquivos!");
	}
	else
	{
		printf ("\nArquivo gerado com sucesso!");
	}
}

//implementação das funções
int criarArquivoOrdenado (char nomeArqA[], char nomeArqB[])
{
	//declaração de variáveis
	FILE *arqB;
	float ultimo = FLT_MAX, valor;
			
	//abrindo o arquivo a ser gerado
	arqB = fopen (nomeArqB, "w");
	
	//verificando se houve erro na abertura do arquivo
	if (!arqB)
	{
		return 0;	//representando que houve erro
	}
	else
	{
		//buscando no arquivo original o maior elemento que seja inferior
		//ao último inserido no novo arquivo
		while (buscarMaiorElemento (nomeArqA, ultimo, &valor) != -1)
		{
			//inserindo no novo arquivo o elemento encontrado
			fprintf (arqB, "%.2f\n", valor);
			
			//atualizando o 'ultimo'
			ultimo = valor;
		}
		
		//fechando o novo arquivo
		fclose (arqB);
		
		return 1;
	}
}

int buscarMaiorElemento (char nomeArq[], float limite, float *maior)
{
	//declaração de arquivos
	FILE *arq;
	float ma = FLT_MIN, numero;
	int mudou = 0;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//houve erro?
	if (!arq)
	{
		return -1;
	}
	else
	{
		//lendo os valores do arquivo
		while (fscanf (arq, "%f", &numero) != EOF)
		{
			//verificando se o número lido é menor do que o limite
			if ((numero < limite) &&
			    (numero > ma)) //e se é maior do que 'ma'
			{
				ma = numero;  //atualizando o maior número
				mudou = 1;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando...
		if (mudou == 1)
		{
			*maior = ma;
			return 1;
		}
		else
		{
			return -1;
		}
	}
}
