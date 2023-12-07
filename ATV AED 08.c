#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

typedef struct{
	char nomeL[30], tipoP[30];
	int cod;
	float preco;
}cadastro;

void menu(){
	printf("\n---------------MENU---------------");
	printf("\n1- Inserir lanche");
	printf("\n2- Lanches cadastrados");
	printf("\n3- Consultar lanche pelo nome");
	printf("\n4- Consultar lanche por tipo de pao");
	printf("\n5- Alterar o preco do lanche");
	printf("\n6- Excluir lanche");
	printf("\n7- Sair\n");

}

void cad_lanche(FILE *p){
	cadastro c;
	
	p=fopen("arquivo.bin", "ab");
	if(p == NULL){
		printf("\nErro no arquivo");
	}
	else{
		printf("\nDigite o nome do lanche:");
		fflush(stdin);
		gets(c.nomeL);
		printf("\nDigite o codigo do lanche:");
		scanf("%d", &c.cod);
		printf("\nDigite o tipo do pao:");
		fflush(stdin);
		gets(c.tipoP);
		printf("\nDigite o preco do lanche:");
		scanf("%f", &c.preco);
		
		fwrite(&c, sizeof(cadastro), 1, p);
	}
	system("cls");
	fclose(p);
}

void listarLanches(){
	system("cls");
	cadastro c;
	FILE *p;
	p = fopen("arquivo.bin","rb");
	if(p == NULL){
		printf("\nErro no arquivo :(");
	}else{
		while(fread(&c,sizeof(cadastro),1,p)==1){
			printf("\nCodigo: %d", c.cod);
			printf("\nNome: %s", c.nomeL);
			printf("\nTipo de pao: %s", c.tipoP);
			printf("\npreco: %.2f", c.preco);
		}
		fclose(p);
	}
}

void consulta_lanche(FILE *p){
	cadastro c;
	char tipoPao[30];
	int encontrou = 0;
	
	p=fopen("arquivo.bin", "rb");
	if(p == NULL){
		printf("\nErro no arquivo");
	}
	else{
		printf("\nDigite o tipo de pao do lanche para consulta: ");
		fflush(stdin);
		gets(tipoPao);
		while(fread(&c, sizeof(cadastro), 1, p)==1){
			if(strcmp(tipoPao, c.tipoP) == 0){
				encontrou = 1;
				printf("\nNome do lanche: %s", c.nomeL);
				printf("\nCodigo do lanche: %d", c.cod);
				printf("\nTipo do pao do lanche: %s", c.tipoP);
				printf("\nPreco do lanche: %.2f\n", c.preco);
			}
		}
		if(!encontrou){
			printf("\n Nenhum lanche com esse tipo de pao encontrado!!!");
		}
	}
	
	system("pause");
	fclose(p);
}

void consulta_nome(FILE *p){
	cadastro c;
	char consulta[50];
	int enc=1;
	p=fopen("arquivo.bin","rb");
	if(p==NULL){
		printf("Erro no arquivo!");
	}
	else{
		printf("\nInforme o nome do lanche para realizar a consulta:");
		fflush(stdin);
		fgets(consulta, sizeof(consulta), stdin);
		consulta[strcspn(consulta,"\n")] = 0; // retira o \n no final da  string para fazer a consulta, \n consta como caracter na tabela.
		
		while(fread(&c, sizeof(cadastro), 1, p)==1){
			if(stricmp(consulta,c.nomeL)==0){
				enc = 1;
				printf("\nCodigo:%d", c.cod);
				printf("\nNome do lanche:%s", c.nomeL);
				printf("\nTipo do pao:%s", c.tipoP);
				printf("\nPreco:%.2f\n", c.preco);
			}
			if(!enc){
				printf("\n!!!Nao encontrado!!!\n");
			}
		}
	}
	system("pause");
	system("cls");
	fclose(p);
}

long int buscar(FILE *p, int codigo_busca){
	
	cadastro c;
	rewind(p);
	fread(&c, sizeof(cadastro), 1, p);
	while(!feof(p) && codigo_busca != c.cod){
		fread(&c, sizeof(cadastro), 1, p);
	}
	if(!feof(p)){
		return (ftell(p) - sizeof(cadastro));
	}
	
	return -1;
}

void alterarPreco(){
	system("cls");
	cadastro c;
	int codigo_busca, posArq;
	float novoPreco;
	FILE *p;
	
	p = fopen("arquivo.bin", "rb+");
	
	if(p == NULL){
		printf("\nErro no arquivo :(");
	}else{
		printf("\nDigite o codigo do lanche para alterar o valor: ");
		scanf("%d", &codigo_busca);
		
		posArq = buscar(p, codigo_busca);
		
		if(posArq == -1){
			printf("\nLanche nao encontrado");
		}else{
			fseek(p,posArq,0);
			fread(&c,sizeof(cadastro),1,p);
			
			printf("\nLanche encontrado!");
			printf("\nCodigo: %d", c.cod);
			printf("\nNome: %s", c.nomeL);
			printf("\nTipo de pao: %s", c.tipoP);
			printf("\npreco: %.2f", c.preco);
			
			printf("\n\n");
			printf("\nDigite o novo preco para o lanche: ");
			scanf("%f", &c.preco);
			fseek(p,posArq,0);
			fwrite(&c,sizeof(cadastro),1,p);
			printf("\nPreco alterado!");
		}
	}
	fclose(p);
}

long int buscar_nome(FILE *p, char nome_busca[30]){
	
	cadastro c;
	rewind(p);
	fread(&c, sizeof(cadastro), 1, p);
	while(!feof(p) && stricmp(nome_busca, c.nomeL)!=0){
		fread(&c, sizeof(cadastro), 1, p);
	}
	if(!feof(p)){
		return (ftell(p) - sizeof(cadastro));
	}
	
	return -1;
}

void excluir_lanche(FILE *p){
	system("cls");
	cadastro c;
	int posArq;
	char nome[30];
	p = fopen("arquivo.bin", "rb");
	
	printf("\nDigite o nome do lanche que voce quer excluir: ");
	fflush(stdin);
	gets(nome);
		
	if(stricmp(nome,'\0')!= 0){
		posArq = buscar_nome(p, nome);
		if(posArq == -1)
			printf("\nNao encontrado");
		else{
			fseek(p, posArq,0);
			fread(&c, sizeof(cadastro),1,p);
			printf("\nCodigo:%d", c.cod);
			printf("\nNome do lanche:%s", c.nomeL);
			printf("\nTipo do pao:%s", c.tipoP);
			printf("\nPreco:%.2f", c.preco);
			printf("\nDeseja excluir? (s/n)\n");
			
			if(toupper(getche())=='S'){
				FILE *temp = fopen("auxiliar.bin", "wb");
				rewind(p);
				fread(&c, sizeof(cadastro),1,p);
				while(!feof(p)){
					if(strcmp(nome, c.nomeL)!= 0)
						fwrite(&c, sizeof(cadastro),1,temp);
					
					fread(&c, sizeof(cadastro), 1, p);
				}
				
				fclose(p);
				fclose(temp);
				remove("arquivo.bin");
				rename("auxiliar.bin", "arquivo.bin");
				
			}
			else{
				fclose(p);
			}
		}
	}getch();
	fclose(p);
}
main()
{
	FILE *p;
	int op;
	char nome[30], pao[30];
	do{
		menu();
		scanf("%d", &op);
		if(op == 1){
			system("cls");
			cad_lanche(p);
		}
			
		if(op == 2){
			listarLanches();
		}
		
		if(op == 3){
			consulta_nome(p);
		}
		
		if(op == 4){
			consulta_lanche(p);
		}
		
		if(op == 5){
			alterarPreco();
		}
		
		if(op == 6){
			excluir_lanche(p);
		}
		
		if(op == 7){
			printf("\nObrigada por acessar o programa!\n");
			system("pause");
		}
	}while(op != 7);
}
