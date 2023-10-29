#include <stdio.h>
#include <string.h>
#define TF 2

typedef struct{
	int horasVolun, codVolun, telefoneVolun;
	char nome[60], cpf[30];
}voluntario;

typedef struct{
	int qtdAlimento, qtdMedicamento, qtdRoupa;
	char alimento[30], medicamento[30], roupa[30];
	float vMonetario; 
}doacao;

typedef struct{
    char nomeP[20], produto[20];
    int opcao, qtdpessoas, dias, horasTotal, horasMax, horasMin, qtdProduto, opcaoPV;
    float valor;
    //opcaoPV = opcao de produto, valor monetario ou os dois;
}projeto;

typedef struct{
	char nomeEmpresa[30];
	int telefoneEmpresa, codEmpresa;
}empresa;

typedef struct{
	char atividade[30], local[30];
	int dia, mes, ano, qtdParticipantes;
}atividade;

typedef struct{
	char c;
	int b;
	float a;
}relatorio;

void menu(){
	printf("\n====MENU====\n");
	printf("1- Gerenciar voluntarios\n");
	printf("2- Gerenciar doacoes\n");
	printf("3- Gerenciar projetos\n");
	printf("4- Gerenciar empresas parceiras\n");
	printf("5- Gerenciar atividades\n");
	printf("6- Emitir relatorios\n");
	printf("7- Finalizar\n\n");
}

int gerenciarVoluntario(voluntario v[]) {
	
	int opc;
	
	printf("1- Cadastrar voluntario\n");
	printf("2- Dispensar voluntario\n");
	printf("3- Lancar horas\n");
	printf("4- Exibir voluntarios\n");
	printf("5- Retornar\n\n");
	scanf("%d", &opc);
	
	if(opc == 1)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 2)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 3)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 4)
	printf("Em desenvolvimento!\n\n");
	
	return opc;
}

int gerenciarDoacao(doacao d[]){
	
	int opc;
	
	printf("\nInforme o tipo de doacao:\n");
	printf("\n1 - Valor monetario");
	printf("\n2 - Medicamento");
	printf("\n3 - Alimento");
	printf("\n4 - Agasalho\n\n");
	printf("\n5 - Retornar");
	scanf("%d", &opc);
	
	if(opc == 1)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 2)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 3)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 4)
	printf("Em desenvolvimento!\n\n");
	
	return opc;
}

int gerenciarProjeto(projeto p[]){
	
    int opc;
    
    printf("1 - Adicionar projeto\n");
    printf("2 - Excluir projeto\n");
    printf("3 - Exibir projetos\n");
    printf("4 - Retornar\n\n");
    scanf("%d", &opc);
    
    if(opc == 1)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 2)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 3)
	printf("Em desenvolvimento!\n\n");
	
	return opc;
    
}

int gerenciarEmpresa(empresa e[]){
	int opc;
	
	printf("\n1 - Adicionar empresa parceira");
	printf("\n2 - Remover empresa da parceria");
	printf("\n3 - Listar empresas\n\n");
	printf("\n4 - Retornar");
	scanf("%d", &opc);
	
	if(opc == 1)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 2)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 3)
	printf("Em desenvolvimento!\n\n");
	
	return opc;
	
}

int gerenciarAtividade(atividade a[]){
	
	int opc;
	
	printf("\n1 - Registrar atividade");
	printf("\n2 - Listar atividades\n\n");
	printf("\n3 - Retornar");
	scanf("%d", &opc);
	
	if(opc == 1)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 2)
	printf("Em desenvolvimento!\n\n");
	
	
	return opc;
}

int emitirRelatorio(relatorio r[]){
	
	int opc;
	
	printf("\n1 - Relatorio de voluntarios");
	printf("\n2 - Relatorio de doacoes");
	printf("\n3 - Certificado de participacao");
	printf("\n4 - Retornar");
	scanf("%d", &opc);
	
	if(opc == 1)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 2)
	printf("Em desenvolvimento!\n\n");
	
	if(opc == 3)
	printf("Em desenvolvimento!\n\n");
	
	return opc;
}


main(){
	
	int opc;
	voluntario v[TF];
	doacao d[TF];
	projeto p[TF];
	empresa e[TF];
	atividade a[TF];
	relatorio r[TF];
	
	menu();
	scanf("%d", &opc);
	
	while(opc != 7){
		
		if(opc == 1){
			printf("\n\n--------GERENCIAR VOLUNTARIOS--------\n\n");
			gerenciarVoluntario(v);
		}
		if(opc == 2){
			printf("\n\n--------GERENCIAR DOACOES--------\n\n");
			gerenciarDoacao(d);
		}
		if(opc == 3){
			printf("\n\n--------GERENCIAR PROJETOS--------\n\n");
			gerenciarProjeto(p);
		}
		if(opc == 4){
			printf("\n\n--------GERENCIAR EMPRESAS PARCEIRAS--------\n\n");
			gerenciarEmpresa(e);
		}
		if(opc == 5){
			printf("\n\n--------GERENCIAR ATIVIDADES--------\n\n");
			gerenciarAtividade(a);
		}
		if(opc == 6){
			printf("\n\n--------EMITIR RELATORIOS--------\n\n");
			emitirRelatorio(r);
		}
		
		menu();
		scanf("%d", &opc);
		
	}
	printf("\nFinalizado.");
}
