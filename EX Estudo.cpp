#include <stdio.h>
#include <string.h>
#define TF 3

typedef struct{
	char nome[60], RA[60];
	float media1, media2, mediaS=0;
}aluno;

void cadastro(aluno a[])
{
	int i;
	
	for(i=0; i<TF; i++)
	{
	printf("\nDigite o nome do aluno: \n");
	fflush(stdin);
	gets(a[i].nome);
	printf("Digite o RA do aluno: \n");
	fflush(stdin);
	gets(a[i].RA);
	printf("Digite a media do primeiro bimestre do aluno:\n");
	scanf("%f", &a[i].media1);
	printf("Digite a media do segundo bimestre do aluno:\n");
	scanf("%f", &a[i].media2);
	a[i].mediaS = (a[i].media1+a[i].media2)/2;
	}
}

void media(aluno a[])
{
	int i;
	char nomeC[60];
	
	printf("\nDigite o nome do aluno que deseja procurar: \n");
	fflush(stdin);
	gets(nomeC);
	
	for(i=0; i<TF; i++)
	{
		if(stricmp(nomeC, a[i].nome)==0)
		{
			printf("\nAluno: %s\n", a[i].nome);
			printf("Media semestral: %.2f\n", a[i].mediaS);
		}	
	}
}

void RAE(aluno a[])
{
	int i, contA=0, contR=0, contE=0;
	
	for(i=0; i<TF; i++)
	{
		if(a[i].mediaS >= 6)
		contA++;
		
		if(a[i].mediaS < 4)
		contR++;
		
		if(a[i].mediaS >= 4 && a[i].mediaS < 6)
		contE++;
	}
	
	printf("\nAlunos Aprovados: %d\n", contA);
	printf("Alunos Reprovados: %d\n", contR);
	printf("Alunos de Exame: %d\n", contE);
}

void mediaM(aluno a[])
{
	int i, contM=0;
	
	for(i=0; i<TF; i++)
	{
		if(a[i].mediaS >= 8)
		contM++;
	}
	
	printf("\nAlunos com media maior ou igual a oito: %d\n", contM);
}

main()
{
	aluno a[TF];
	
	int opcao;
	
	printf("\n=======MENU=======\n");
	printf("1- Cadastrar alunos\n");
	printf("2- Ver dados do aluno\n");
	printf("3- Alunos reprovados, aprovados e de exame\n");
	printf("4- Alunos acima ou igual a 8\n");
	printf("5- Sair\n");
	scanf("%d", &opcao);
	printf("==================\n");
	
	while(opcao < 5)
	{
		if(opcao == 1)
			cadastro (a);
			
		if(opcao == 2)
			media (a);
			
		if(opcao == 3)
			RAE (a);
			
		if(opcao == 4)
			mediaM (a);
			
		printf("\n=======MENU=======\n");
		printf("1- Cadastrar alunos\n");
		printf("2- Ver dados do aluno\n");
		printf("3- Alunos reprovados, aprovados e de exame\n");
		printf("4- Alunos acima ou igual a 8\n");
		printf("5- Sair\n");
		scanf("%d", &opcao);
		printf("==================\n");
	}
	
	printf("\nPROGRAMA ENCERRADO\n");
}
