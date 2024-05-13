#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // Funcao resp por cadastrar os usuarios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criacao de variaveis/string
	
	printf ("Digite o CPF a ser cadastrado: "); //coletando informacao so usuario
	scanf("%s", cpf); //%s usa-se para salvar a entrada do usuario a uma string (aqui no caso o cpf)
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo no modo "w" significa escrever
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo de acrescentar nova linha ("a")
	fprintf(file, ", "); // fprintf acrescenta dado ao arquivo, enquanto que printf acrescenta dado na tela do usuario
	fclose(file); //salva o arquivo corretamente e o fecha, liberando espaco
	
	printf("Digite o nome a ser cadastrado: "); //coletando informacao so usuario
	scanf("%s", nome); // salvando a entrada do usuario na variavel/string nome
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo de acrescentar nova linha
	fprintf(file, nome); // salva o valor da variavel
	fclose(file); //salva o arquivo corretamente e o fecha, liberando espaco
	
	file = fopen(arquivo, "a");// abre o arquivo no modo de acrescentar nova linha
	fprintf(file, " "); // salva o valor da variavel
	fclose(file); //salva o arquivo corretamente e o fecha, liberando espaco
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informacao so usuario
	scanf("%s", sobrenome); // associando a entrada do usuario a uma string ("sobrenome")
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo de acrescentar nova linha
	fprintf (file, sobrenome); // salva o valor da variavel
	fclose(file); //salva o arquivo corretamente e o fecha, liberando espaco
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo de acrescentar nova linha ou dado
	fprintf(file, ", "); // salva o valor da variavel
	fclose(file); //salva o arquivo corretamente e o fecha, liberando espaco
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informacao so usuario
	scanf("%s", cargo); // associando a entrada do usuario a uma string ("cargo")
	
	file = fopen(arquivo, "a"); // abre o arquivo no modo de acrescentar nova linha
	fprintf (file, cargo); // salva o valor da variavel
	fclose(file); //salva o arquivo corretamente e o fecha, liberando espaco
	
	printf("Deseja cadastrar outro CPF? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 'S' || resposta == 's') 
	{
		
        registro();
        
    }
	
}

int consulta() // Funcao resp por consultar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf [40]; 
	char conteudo[200]; 
	
	printf("Digite o CPF a ser consultado: "); //coletando informacao so usuario
	scanf("%s", cpf); //Le o CPF digitado pelo usuario e armazena na variavel 'cpf'
	
	FILE *file; // Declara um ponteiro para arquivo
	file=fopen(cpf, "r"); // Abre o arquivo com o nome do CPF em modo de leitura
	
	if(file==NULL) // Verifica se o arquivo nao pode ser aberto
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); // Exibe uma mensagem de erro
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Enquanto houver conteudo para ler no arquivo
	{
		printf("\nEssas são as informações do usuário: "); // Exibe uma mensagem
		printf("%s", conteudo); // Imprime o conteúdo do arquivo
		printf("\n\n"); // Imprime duas quebras de linha
	}
	
	printf("Deseja consultar outro CPF? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 'S' || resposta == 's') 
	{
		
        consulta();
        
    }
}

int deletar() // Funcao resp por deletar os usuarios no sistema
{	

	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem

	char cpf[40]; // Declara uma variável para armazenar o CPF
	
	printf("Digite o CPF a ser deletado: "); // Solicita o CPF ao usuario
	scanf("%s", cpf); // Le o CPF digitado pelo usuario e armazena na variavel 'cpf'
	
	FILE *file; // Declara um ponteiro para arquivo
	file = fopen(cpf, "r"); // Abre o arquivo com o nome do CPF em modo de leitura
	fclose(file); // Fecha o arquivo
	
	if (file == NULL) // Verifica se o arquivo nao pôde ser aberto
	{
		printf("\nCPF não localizado!\n\n"); // Exibe uma mensagem de erro
		system("pause"); // Pausa o programa para esperar a entrada do usuário
	}
	
	remove(cpf); // Remove o arquivo com o nome do CPF
	
	if (file != NULL) // Verifica se o arquivo foi deletado
	{
		
		printf ("\nUsuário deletado com sucesso!\n\n"); // Exibe uma mensagem de sucesso
		
	}
	
	printf("Deseja deletar outro CPF? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 'S' || resposta == 's') 
	{
		
        deletar();
        
    }
	
}

int main()
{
	 int opcao=0; // Declaracao da variavel para a opcao do menu
	 int laco=1; // Declaracao da variavel para controlar o laco de repeticao
	 
	 for (laco=1;laco=1;) // Loop principal
	 {
	 	system ("cls"); // Limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); // armazenando a esolha do usuario
	
		system("cls"); // resp por limpar a tela
		
		switch (opcao) //inicio da selecao do menu
		{
			case 1: //se a entrada for 1 chamar a funcao a seguir
			registro(); //chamada de funcao
			break; // interrompe a execucaoo do loop
			
			case 2:
			consulta(); //chamada de funcao
			break; // interrompe a execucaoo do loop
			
			case 3:
			deletar(); //chamada de funcao
			break; // interrompe a execucaoo do loop
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n\n"); // Exibe uma mensagem de erro
			system("pause"); // Pausa o programa para esperar a entrada do usuario
			// fim da selecao
		}
	
	}
}
