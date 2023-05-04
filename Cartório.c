#include <stdio.h>  //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Bibioteca respons�vel por cuidar das strings

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o das vari�veis(strings)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se as strings
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo(w = writing)
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//In�cio da cria��o das vari�veis
	char cpf[40];
	char conteudo[200];
	//Final da cria��o das vari�veis
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo(r = reading)
	
	if(file == NULL)
	{
		printf("Usu�rio n�o consta no sistema.\n"); //Negativa caso o usu�rio n�o conste no sistema
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Apresenta as informa��es do usu�rio desejado
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar() //Fun��o respons�vel por deletar os usu�rios do sistema
{
	//Cria��o das vari�veis
	char cpf[40];
	//Final da cria��o da vari�vel
	
	printf("Digite o CPF a ser deletado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o consta no sistema.\n"); //Afirmativa ap�s realizar a exclus�o do usu�rio
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\tCart�rio da EBAC\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); //Menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) //In�cio da sele�o do menu
		{
			case 1:
			registrar(); //Op��o que chama a fun��o registrar do menu
			break;
			
			case 2:
			consultar(); //Op��o que chama a fun��o consultar do menu
			break;
			
			case 3:
			deletar(); //Op��o que chama a fun��o deletar do menu
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break; //Fim da sele��o
		}
	}
	
}
