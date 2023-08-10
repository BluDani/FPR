/*
Quest�o 01:
Suponha que n�o existissem as fun��es strlen,
strcpy, strcat e strcmp. Pede-se, ent�o, a
implementa��o de fun��es que tenham o
mesmo objetivo daquelas.
*/

#include<stdio.h>

//Prot�tipo da fun��o
int strlen(char str1[]);
void strcpy(char str1[], char str2[]);
void strcat(char str1[], char str2[]);
int strcmp(char str1[], char str2[]);
void exibirString(char str[]);

void main(){
	char string1[20] = "Daniel", string2[20] = "Alex";
	int quantidade, resultado;
	
	//lendo quantos caracteres tem na string
	quantidade = strlen(string1);
	
	printf("Tem %d caracteres na string", quantidade);
	
	//copiando uma string
	strcpy(string1, string2);
	
	exibirString(string2);
	
	//juntando duas strings
	strcat(string1, string2);
	
	exibirString(string1);
	
	resultado = strcmp(string1, string2);
	
	printf("\nResultado = %d", resultado);
}

//Fun��o para contar quantos caracteres tem na string
int strlen(char str1[]){
	int i, cont = 0;
	
	for(i = 0; str1[i]; i++){
		cont++;
	}
	
	return cont;
}

//Fun��o para copiar uma string
void strcpy(char str1[], char str2[]){
	int i, j;
	
	for(i = 0; str1[i]; i++){
		j = i;
		
		str2[i] = str1[i];
	}
	
	str2[i] = '\0';
}

//Fun��o para juntar 2 strings
void strcat(char str1[], char str2[]){
	int i, j;
	
	i = strlen(str1);
	
	for(i, j = 0; str2[j]; i++, j++){
		
		str1[i] = str2[j];
	}
	
}

//Fun��o para comparar strings
int strcmp(char str1[], char str2[]){
	int i;
	
	for(i = 0; (str1[i]) && (str2[i]) && (str1[i] == str2[i]); i++){
		
		if(!str1[i] && !str2[i]){
			return 0;
		}
		else{
			
			if(str1[i] > str2[i]){
				return 1;
			}
			else{
				return -1;
			}
		}
	}
	
	return -1;
}

void exibirString(char str[]){
	int i;
	
	printf("\nString = ");
	
	for(i = 0; str[i] !='\0'; i++){
		
		printf("%c", str[i]);
	}
}
