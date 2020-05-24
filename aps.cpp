//            APS - Estrutura de Dados
//Carolina Martins - RA: 795099
//Paulo Arthur Furtado da Silva - RA: 3489279
//Pedro Henrique Santana Lima - 3812977
//Rennan Vaz Rosa - 3399446

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char disciplina[10][100], disciplinaAluno[10][100], alunos[10][100];
int i, j, d=0, a=0, continuar=1;
float notas[10][3], mediaAlunos[10];

int menu(){   //  Menu Inicial
	int escolha, menu=2, i = 0;
	char cadastrarDisciplina(), cadastrarAluno(), mostrarRelatorio(int i);
	float lancarNota(), alterarNota();
	
	while(menu==2){
		continuar = 1;
		system("cls");

		//Menu Inicial
		printf("   ---  Sistema de Gerenciamento de Alunos  --- \n               ---  Menu Inicial  ---\n\n1 - Cadastrar Disciplina\n2 - Cadastrar Aluno\n3 - Lançar Nota\n4 - Alterar Nota\n5 - Mostrar Relatório dos Estudantes\n6 - Encerrar o Programa\n\nDigite sua opção: ");
		scanf("%d",&escolha);
		
		switch(escolha){
			case 1 :
				system("cls");
				cadastrarDisciplina();
			break;
			
			case 2 :
				system("cls");
				cadastrarAluno();
			break;
			
			case 3 :
				system("cls");
				lancarNota();
			break;
			
			case 4 :
				system("cls");
				alterarNota();
			break;
			
			case 5 :
				system("cls");
				mostrarRelatorio(i);
			break;
			
			case 6 :
				printf("O programa será encerrado.");
				return 0;
		}
	}
}

char cadastrarDisciplina(){  // Cadastra as Disciplinas e cria uma Lista delas
	while(continuar==1){
		printf("\nDigite o nome da disciplina: ");
		fflush(stdin);
		gets(disciplina[d]);
		d++;
		system("cls");
		
		printf("\nLista de Disciplinas:\n");
		for(i=0;i<10;i++){
			printf("%d - %s\n", i, disciplina[i]);
		}
		
		i = 0;
		while(i==0){
			printf("\nDeseja cadastrar outra disciplina?\n1 - Sim\n2 - Não\nDigite sua escolha: ");
			scanf("%d",&continuar);
			if(continuar==1){
				i = 1;
				continuar = 1;
			} else if(continuar==2){
				i = 1;
				continuar = 0;
			} else {
				i=0;
				printf("\n\nOpção Inválida.\n\n");
				
			}
		}
	}
}

char cadastrarAluno(){   // Cadastra o Nome e Disciplina do Aluno
	int escolhaErrada;
	
	while(continuar==1){
		printf("\nDigite o nome do aluno: ");
		fflush(stdin);
		gets(alunos[a]);
		
		escolhaErrada = 1;
		while(escolhaErrada==1){
			printf("\nLista de Disciplinas:\n");
			for(i=0;i<10;i++){
				printf("%d - %s\n", i, disciplina[i]);
			}
		
			printf("\nDigite o número da disciplina do aluno: ");
			scanf("%d", &i);
			
			if(strcmp(disciplina[i],"")==0){
				printf("\nO campo escolhido não apresenta matéria registrada.\n\n");
				system("pause");
				system("cls");
				escolhaErrada = 0;
				menu();
			} else {
				if(i<0 || i>10){
				printf("Escolha inválida.\n");
				escolhaErrada = 1;
				system("pause");
				system("cls");
			} else if(strcmp(disciplina[i],"")==0){
				printf("Escolha inválida.\n");
				escolhaErrada = 1;
				system("pause");
				system("cls");
			} else {
				escolhaErrada = 0;
			}
			}
		}
		
		// Esse "for" registra a materia de acordo com o numero do aluno
		for(j=0;j<100;j++){
			disciplinaAluno[a][j] = disciplina[i][j];
		}
		
		a++;
		system("cls");
		
		printf("\nLista de Alunos:\n");
		for(i=0;i<10;i++){
			printf("%d - Aluno: %s - Disciplina: %s\n", i, alunos[i], disciplinaAluno[i]);
		}
		
		i = 0;
		while(i==0){
			printf("\nDeseja cadastrar outro aluno?\n1 - Sim\n2 - Não\nDigite sua escolha: ");
			scanf("%d",&continuar);
			if(continuar==1){
				i = 1;
				continuar = 1;
			} else if(continuar==2){
				i = 1;
				continuar = 0;
			} else {
				i=0;
				printf("\n\nOpção Inválida.\n\n");
				
			}
		}
	}
}

float lancarNota(){    // Cadastra as Notas do Aluno
	char nome[100];
	int contador=0, notaErrada;
	
	printf("  ---  Inserir Notas dos Alunos  --  \n ");
	
	//exibe a lista de alunos com suas respectivas materias
	printf("\nLista de Alunos:\n");
	for(i=0;i<10;i++){
		printf("%d - Aluno: %s - Disciplina: %s\n", i, alunos[i], disciplinaAluno[i]);
	}
	
	printf("\nDigite o nome do aluno que terá a nota cadastrada: ");
	scanf("%s", &nome);
	
	//busca o nome do aluno digitado
	contador = 0;
	for(i=0;i<10;i++){
		if(strcmp(nome,alunos[i])==0){
			
			if(notas[i][0]!=0 && notas[i][1]!=0 && notas[i][2]!=0){
				printf("A nota já foi cadastrada.\n\n");
				system("pause");
			} else {
			
			printf("\nAluno encontrado.\n");
				for(j=0;j<3;j++){
					notaErrada = 1;
					//Essa condição while serve para evitar que o usuário digite um nota que não esteja entre 0 e 10.
					while(notaErrada == 1){
						printf("Digite a %d° nota: ", j+1);
						scanf("%f", &notas[i][j]);
	
						if(notas[i][j]<0){
							printf("Digite uma nota maior ou igual a 0.\n\n");
							notaErrada = 1;
							system("pause");
						} else if(notas[i][j]>10){
							printf("Digite uma nota menor ou igual a 10.\n\n");
							notaErrada = 1;
							system("pause");
						} else {
							notaErrada = 0;
						}
					}
				}
			}
			
			// Calcula a média do aluno
			mediaAlunos[i] = (notas[i][0] + notas[i][1] + notas[i][2])/3;
			
		} else {
			contador++;
		}
		
		if(contador==10){
			printf("O nome digitado não está cadastrado.\n\n");	
			system("pause");
		}
	}
}

float alterarNota(){   // Altera as Notas do Aluno
	char nome[100];
	int contador=0, notaErrada, n;
	
	printf("  ---  Alterar Notas dos Alunos  --  \n ");
	printf("\nLista de Alunos:\n");
	for(i=0;i<10;i++){
		if(strcmp(alunos[i],"")==0){
			//Se um campo da lista estiver vazio, não será mostrado
		} else {
			printf("%d - Aluno: %s - Disciplina: %s - Nota 1: %.2f - Nota 2: %.2f - Nota 3: %.2f\n", i, alunos[i], disciplinaAluno[i], notas[i][0], notas[i][1], notas[i][2]);
		}
	}
	printf("\nDigite o nome do aluno que terá a nota alterada: ");
	scanf("%s", &nome);
	
	contador = 0;
	for(i=0;i<10;i++){
		if(strcmp(nome,alunos[i])==0){
			printf("\nAluno encontrado.\n");
			
			if(notas[i][0]==0 && notas[i][1]==0 && notas[i][2]==0){
				printf("A nota não pode ser alterada porque ainda não foi cadastrada.\n\n");
				system("pause");
			} else {
					notaErrada = 1;
					while(notaErrada == 1){
						printf("Digite a nota que deseja alterar: \n0 - Primeira Nota\n1 - Segunda Nota\n2 - Terceira Nota\nDigite: ", j+1);
						scanf("%d", &n);
						
						if(n<0  || n>2){
							printf("Opção inválida.\n\n");
							system("pause");
							system("cls");
							notaErrada = 0;
						} else {
								printf("Digite o novo valor da nota %d: ", n+1);
							scanf("%f", &notas[i][n]);
		
							if(notas[i][n]<0){
								printf("Digite uma nota maior ou igual 0.\n\n");
								notaErrada = 1;
								system("pause");
							} else if(notas[i][n]>10){
								printf("Digite uma nota menor ou igual a 10.\n\n");
								notaErrada = 1;
								system("pause");
							} else {
								printf("Nota alterada com sucesso!\n\n");
								system("pause");
								notaErrada = 0;
							}
						}
					}
				
			}
			
			// Calcula a média do aluno
			mediaAlunos[i] = (notas[i][0] + notas[i][1] + notas[i][2])/3;
		} else {
			contador++;
		}
		
		if(contador==10){
			printf("O nome digitado não está cadastrado.\n\n");	
			system("pause");
		}
	}
}

mostrarRelatorio(int i){   // Exibe o Relatorio dos Alunos, Notas e Matérias cadastradas usando Recursividade
char c;
	if(strcmp(alunos[i],"")==0 || i>=10){
		//se um campo da lista estiver vazio, não será mostrado
		} else {
			//Define o conceito do aluno
			if(mediaAlunos[i]>=8.5){
				c = 'A';
			} else if(mediaAlunos[i]>=7){
				c = 'B';
			} else if(mediaAlunos[i]>=6){
				c = 'C';
			} else if(mediaAlunos[i]>=4){
				c = 'D';
			} else {
				c = 'F';
			}
			printf("%d - Aluno: %s - Disciplina: %s - Nota 1: %.2f - Nota 2: %.2f - Nota 3: %.2f - Média: %.2f - Conceito: %c\n", i, alunos[i], disciplinaAluno[i], notas[i][0], notas[i][1], notas[i][2], mediaAlunos[i], c);
		}
		if(i==9){
			system("pause");
			menu();
		}
		mostrarRelatorio(i+1);
		system("pause");
		
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	menu();
}
