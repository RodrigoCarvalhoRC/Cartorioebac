#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de textos por região
#include <string.h>// biblioteca responsável por cuidar das string

int registro()// Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cpf);//%s refere-se a string
	
		strcpy(arquivo, cpf);//Responsável por copiar os valores das string
	
		FILE *file;//cria o arquivo
		file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
		fprintf(file,cpf);//salvo o arquivo
		fprintf(file,",");//coloca uma virgula no arquivo
		fclose(file);//fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",nome);//%s refere-se a string

		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fprintf(file,",");
		fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fprintf(file,",");
		fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
	
	printf("Registro cadastrado com sucesso\n\n");
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) //busca informação toda do texto
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		fclose(file);
		system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	int pergunta=0;
	
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) //busca informação toda do texto
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
	printf("Deseja deletar esse registro? Se sim digite 1 se não digite 2\n");
	scanf("%d", &pergunta);
	fclose(file);
	
	switch(pergunta)
	{
		case 1:
		remove(cpf);
		printf("Registro deletado\n");
		system("pause");
		break;
		
		case 2:
		printf("Registro não deletado\n");
		system("pause");
		break;
	
		default:
		printf("Opção digitada incorreta!");
		system("pause");
		break;
	}
	
}


int main()
{
	int opcao=0; // Definindo variáveis
	int laco=1;

	
	for(laco=1;laco=1;)
	
		{

	system("cls");//responsáveil por deletar a tela
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Cartório da EBAC ###\n\n"); //início do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair\n")
	printf("Opção:"); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuário
	
	system("cls");//responsáveil por deletar a tela
	
	switch(opcao)
	 {
		case 1:
			registro();
			break;
		
		case 2:
			consulta();
			break;
		
		case 3:
			deletar();
			break;
		
		case 4:
			print("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
		default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}	
	}
}
