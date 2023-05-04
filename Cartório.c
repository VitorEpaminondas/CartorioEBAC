#include <stdio.h>  //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Bibioteca responsável por cuidar das strings

int registrar() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação das variáveis(strings)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s refere-se as strings
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo(w = writing)
	fprintf(file,cpf); //Salvo o valor da variável
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

int consultar() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Início da criação das variáveis
	char cpf[40];
	char conteudo[200];
	//Final da criação das variáveis
	
	printf("Digite o CPF a ser consultado: "); //Coletando informações do usuário
	scanf("%s",cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo(r = reading)
	
	if(file == NULL)
	{
		printf("Usuário não consta no sistema.\n"); //Negativa caso o usuário não conste no sistema
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); //Apresenta as informações do usuário desejado
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar() //Função responsável por deletar os usuários do sistema
{
	//Criação das variáveis
	char cpf[40];
	//Final da criação da variável
	
	printf("Digite o CPF a ser deletado: "); //Coletando informações do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não consta no sistema.\n"); //Afirmativa após realizar a exclusão do usuário
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\tCartório da EBAC\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n"); //Menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) //Início da seleão do menu
		{
			case 1:
			registrar(); //Opção que chama a função registrar do menu
			break;
			
			case 2:
			consultar(); //Opção que chama a função consultar do menu
			break;
			
			case 3:
			deletar(); //Opção que chama a função deletar do menu
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break; //Fim da seleção
		}
	}
	
}
