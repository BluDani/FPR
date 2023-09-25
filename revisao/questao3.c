#include<stdio.h>

#define TAM 30

//Protótipo da função
void copiarString(char s1[TAM], char s2[TAM], char s3[TAM]);
int buscarCaracter(char ch[], char str3[]);

void main(){
	char string1[TAM] = "FAL";
	char string2[TAM] = "CAW";
	char string3[TAM];
	
	copiarString(string1, string2, string3);
}

void copiarString(char s1[TAM], char s2[TAM], char s3[TAM]){
	int i, j;
	int res;
	
	for(i = 0; s1[i]; i++){
		
		res = buscarCaracter(s1[i], s2);
		
		if(res == 1){
			s3[j] = s1[i];
			j++;
		}
	}
	
	s3[j + 1] = "\o";
	printf("%s", s3);
}

int buscarCaracter(char ch[], char str2[]){
	int i;
	
	for(i = 0; str2[i]; i++){
		
		if(ch == str2[i]){
			return 0;
		}
	}
	
	return 1;
}

/*
for(j = i; s2[j]; j++){
			
			if(s1[i] != s2[j]){
				res = buscarCaracter(s1, s3);
				
				if(res == 1){
					s3[i] = s1[i];
				}
			}
		}
*/
