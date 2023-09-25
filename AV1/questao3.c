/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	
	Prova a compor a AV1 (Parte II) - 11/05/2023
	
	Questão 03 [2,5 pontos]:
	Dadas duas strings s1 e s2, implementar uma função que crie duas 
	outras strings - s3 e s4 - com as seguintes características:

	- s3: conterá todos os caracteres de s1 que também estão em s2;
	- s4: conterá todos os caracteres de s1 que não estão em s2.

	Exemplo: 

		s1:	"PROGRAMACAO"				
		s2:	"ALGORITMOS"				

		s3: "ROGRAMAAO" 
		s4: "PC"
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void criandoString(char str1[], char str2[], char str3[], char str4[]);
int buscarCaracter(char ch, char str[]);

//main
void main ()
{
	//declaração de variáveis
	char string1[20],
	     string2[20],
		 string3[20],
		 string4[20]; 
		 
	//inicializando as duas strings
	strcpy (string1, "PROGRAMACAO");
	strcpy (string2, "ALGORITMOS");
	
	//chamando a função e armazenando os resultados em 'string3' e 'string4'
	criandoString(string1, string2, string3, string4);
	
	//exibindo as novas strings
	printf ("\n\nstring3: %s\n", string3);
	printf ("string4: %s\n", string4);
}
	
//implementação das funções
void criandoString(char str1[], char str2[], char str3[], char str4[]){
	int i, j = 0, k = 0, res;
	
	for(i = 0; str1[i]; i++){
		
		res = buscarCaracter(str1[i], str2);
		
		if(res == 1){
			str3[j] = str1[i];
			j++;
		}
		else{
			str4[k] = str1[i];
			k++;
		}
	}
	
	str3[j] = '\0';
	str4[k] = '\0';
}

int buscarCaracter(char ch, char str[]){
	int i;
	
	for(i = 0; str[i]; i++){
		
		if(ch == str[i]){
			return 1;
		}
	}
	
	return 0;
}
