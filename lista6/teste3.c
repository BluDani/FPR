/*
Quest�o 03:
Determinada institui��o de ensino armazena,
sob a forma de vetores (de structs), as
seguintes informa��es:
? Alunos: nome, matr�cula;
? Disciplinas do curso: nome, c�digo;
? Inscri��es realizadas: matr�cula do aluno,
c�digo da disciplina, semestre da inscri��o
(semestre/ano).

Pede-se o desenvolvimento de fun��es que
realizem as seguintes opera��es:
i. Exibir, para cada aluno, o total de inscri��es
j� realizadas;
ii. Dado um semestre, informar para cada
disciplina o n�mero de alunos inscritos.
*/

#include<stdio.h>

#define TAM 3

typedef struct{
	char nome[30];
	int matricula;
	int numCursando;
	
} TAlunos;

typedef struct{
	char nome[30], codigo[10];
	int numAlunos;

} TDisciplinas;

typedef struct{
	int semestre, ano, matricula;
	char codigo[10];
	
} TInscricoes;

typedef struct{
	TAlunos aluno;
	TDisciplinas curso;
	TInscricoes inscricao;
	
} TInstituicao;

//Prot�tipo da fun��o
void preencherStruct(TInstituicao s[], int quant);
void exibirStruct(TInstituicao s[], int quant);

void main(){
	TInstituicao escola[TAM];
	
	preencherStruct(escola, TAM);
	exibirStruct(escola, TAM);
}

void preencherStruct(TInstituicao s[], int quant){
	int i;
	
	printf("Preencha os cursos");
	
	for(i = 0; i < quant; i++){
		printf("\nNome do Curso: ");
		gets(s[i].curso.nome);
		
		printf("Codigo do curso: ");
		gets(s[i].curso.codigo);
	}
	
	printf("\n\nPreencha os alunos");
	
	for(i = 0; i < quant; i++){
		printf("\nNome do aluno: ");
		fflush(stdin);
		gets(s[i].aluno.nome);
		
		printf("Matricula do aluno: ");
		scanf("%d", &s[i].aluno.matricula);
	}
}

void fazerInscricao(TInstituicao s[], int quant){
	int i, j;
	
	for(i = 0; i < quant; i++){
		printf("Matricula do aluno: ");
		scanf("%d", &s[i].inscricao.matricula);
		
		printf("Codigo do curso: ");
		gets(s[i].inscricao.codigo);
		
		printf("Semestre (semestre ano): ");
		scanf("%d %d", &s[i].inscricao.semestre, &s[i].inscricao.ano);
		
		for(j = 0; j < quant; j++){
			if(s[i].inscricao.codigo == s[j].curso.codigo){
				s[j].curso.numAlunos += 1;
			}
			
			if(s[i].inscricao.matricula == s[j].aluno.matricula){
				s[j].aluno.numCursando += 1;
			}
		}
	}
}

void exibirStruct(TInstituicao s[], int quant){
	int i;
	
	printf("\ncursos");
	
	for(i = 0; i < quant; i++){
		printf("\n\nCurso de %s", s[i].curso.nome);
		
		printf("\nCodigo: %s", s[i].curso.codigo);
	}
	
	printf("\n\nAlunos");
	
	for(i = 0; i < quant; i++){
		printf("\n\nAluno: %s", s[i].aluno.nome);
		
		printf("\nMatricula: %d", s[i].aluno.matricula);
	}
}
