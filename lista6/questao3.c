/*
Questão 03:
Determinada instituição de ensino armazena,
sob a forma de vetores (de structs), as
seguintes informações:
? Alunos: nome, matrícula;
? Disciplinas do curso: nome, código;
? Inscrições realizadas: matrícula do aluno,
código da disciplina, semestre da inscrição
(semestre/ano).

Pede-se o desenvolvimento de funções que
realizem as seguintes operações:
i. Exibir, para cada aluno, o total de inscrições
já realizadas;
ii. Dado um semestre, informar para cada
disciplina o número de alunos inscritos.
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

//Protótipo da função
void preencherStruct(TInstituicao s[], int quant);
void fazerInscricao(TInstituicao s[], int quant);
void exibirTotalInscricao(TInstituicao s[], int quant);
void numAlunosInscritos(TInstituicao s[], int quant, int semestre, int ano);
void exibirStruct(TInstituicao s[], int quant);

void main(){
	TInstituicao escola[TAM];
	int semestre, ano;
	
	preencherStruct(escola, TAM);
	exibirStruct(escola, TAM);
	
	fazerInscricao(escola, TAM);
	exibirTotalInscricao(escola, TAM);
	
	printf("\n\nDigite o semestre (semestre ano): ");
	scanf("%d %d", &semestre, &ano);
	
	numAlunosInscritos(escola, TAM, semestre, ano);
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
		printf("\n\nMatricula do aluno: ");
		scanf("%d", &s[i].inscricao.matricula);
		
		printf("Codigo do curso: ");
		fflush(stdin);
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

void exibirTotalInscricao(TInstituicao s[], int quant){
	int i;
	
	for(i = 0; i < quant; i++){
		printf("\nO aluno %s esta inscrito em %d cursos", s[i].aluno.nome, s[i].aluno.numCursando);
	}
}

void numAlunosInscritos(TInstituicao s[], int quant, int semestre, int ano){
	int i;
	
	for(i = 0; i < quant; i++){
		if((semestre == s[i].inscricao.semestre) && (ano == s[i].inscricao.ano)){
			printf("\nA disciplina %s tem %d alunos", s[i].curso.nome, s[i].curso.numAlunos);
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
