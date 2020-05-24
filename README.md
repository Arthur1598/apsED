# apsED
Nessa atividade propomos o desenvolvimento de um sistema de gerenciamento acadêmico.

Sistema de Gerenciamento de Aluno

FMU - Ciência da Computação - 3° Semestre
APS - Estrutura de Dados
Professor: Ariel

Grupo:
Carolina Martins
Paulo Arthur Furtado da Silva
Pedro Henrique Santana Lima
Rennan Vaz Rosa

O projeto é um sistema que registra o nome, as três notas, calcula a média e, com base nela, define o conceito de até dez alunos de acordo com a matéria escolar de cada um.

Suas funcionalidades são:
- Cadastrar Disciplína: O usuário pode registrar até 10 disciplinas. A lista de disciplinas vai sendo preenchida da posição 0 até a 9.
- Cadastrar Aluno: O usuário pode registrar até 10 alunos. A lista de alunos vai sendo preenchida da posição 0 até a 9.
- Lançar Nota: O usuário registra as três notas de um aluno registrado. Não é possível registrar as notas de um aluno mais de uma vez.
- Alterar Nota: O usuário altera as três notas de um aluno registrado. Não é possível alterar as notas que ainda não foram registradas.
- Mostrar Relatório: Uma lista é exibida ao usuário detalhando as seguintes informações do aluno: nome, disciplina, avaliação 1, avaliação 2, avaliação 3, média e conceito.

Recursos Utilizados: O projeto utiliza uma função para cada funcionalidade. Com execeção da função Mostrar Relatório, todas as funções possuem "if" e laços de repetição para permitir ao usuário registrar informações várias vezes, evitar erros de digitação durante as escolhas de funcionalidade e organizar as informações digitadas e armazenadas em matrizes e vetores. Em Mostrar Relatório, foi utilizado recursividade onde a função exibe uma linha com informações de um aluno e em seguida chama outra função própria para exibir o próximo aluno até o último.
