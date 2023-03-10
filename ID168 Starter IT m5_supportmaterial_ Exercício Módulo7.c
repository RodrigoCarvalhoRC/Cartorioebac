#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de textos por regi?o
#include <string.h>// biblioteca respons?vel por cuidar das string

int registro()// Fun??o respons?vel por cadastrar os usu?rios no sistema
{
	//inicio cria??o de vari?veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria??o de vari?veis/string
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa??o do usu?rio
	scanf("%s",cpf);//%s refere-se a string
	
		strcpy(arquivo, cpf);//Respons?vel por copiar os valores das string
	
		FILE *file;//cria o arquivo
		file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
		fprintf(file,cpf);//salvo o arquivo
		fprintf(file,",");//coloca uma virgula no arquivo
		fclose(file);//fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa??o do usu?rio
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
		printf("N?o foi possivel abrir o arquivo, n?o localizado! \n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) //busca informa??o toda do texto
	{
		printf("Essas s?o as informa??es do usu?rio: ");
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
	
	
	printf("Digite o CPF do usu?rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu?rio n?o se encontra no sistema!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) //busca informa??o toda do texto
	{
		printf("Essas s?o as informa??es do usu?rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
	printf("Deseja deletar esse registro? Se sim digite 1 se n?o digite 2\n");
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
		printf("Registro n?o deletado\n");
		system("pause");
		break;
	
		default:
		printf("Op??o digitada incorreta!");
		system("pause");
		break;
	}
	
}


int main()
{
	int opcao=0; // Definindo vari?veis
	int laco=1;

	
	for(laco=1;laco=1;)
	
		{

	system("cls");//respons?veil por deletar a tela
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Cart?rio da EBAC ###\n\n"); //in?cio do menu
	printf("Escolha a op??o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Op??o: "); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usu?rio
	
	system("cls");//respons?veil por deletar a tela
	
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
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
		default:
			printf("Essa op??o n?o est? dispon?vel\n");
			system("pause");
			break;
		}	
	}
}
