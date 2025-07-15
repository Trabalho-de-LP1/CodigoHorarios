# Organização de Horários
Trabalho de Linguagem de Programação 1
## Integrantes do Trabalho:
Iago Calazans Silva Ramos <br>
Marcos Vitor Silva Vasconcelos <br>
Maria Clara Silva Lopes <br>
## Trabalho e seu objetivo <b>:

O objetivo desse trabalho é aplicar conceitos de Teoria dos Grafos e Coloração de Grafos para resolver um problema real de alocação de horários escolares de forma otimizada, evitando conflitos de turmas com alunos em comum.

# Propósito e Aplicação

Determinar a mínima quantidade de horários distintos necessária para alocar todas as turmas de uma escola, de forma que nenhuma turma com alunos em comum tenha aula no mesmo horário, garantindo uma grade horária eficiente e livre de conflitos.

### Implementação 
O código principal desenvolvido em linguagem C realiza essa tarefa da seguinte forma: o programa lê um arquivo de entrada contendo o número de turmas e os pares de turmas com conflitos; cria um grafo na forma de matriz de adjacência; preenche esse grafo com base nos conflitos informados; e aplica um algoritmo de coloração de vértices, atribuindo um horário (cor) a cada turma, de modo que turmas com conflitos não compartilhem o mesmo horário. Por fim, o programa exibe a alocação de horários e libera a memória utilizada.

# Instrução para utilização do programa
1- O programa deve ser executado em um compilador de linguagem C;

2- O arquivo a ser analisado deve estar no mesmo diretório do programa;

3- Para executar, no terminal digite os seguintes comando: "gcc main.c funcoes/io.c funcoes/grafo.c funcoes/colirir.c -o horarios", depois digite "./horarios";

4- Escreva o nome do arquivo a ser analisado;

5- O arquivo com a resposta sera criado no diretório do programa;

# Enunciado do desafio

Uma escola está organizando os horários das aulas para diferentes turmas. Cada turma possui um conjunto de alunos, e algumas turmas compartilham alunos em comum. Para evitar conflitos, nenhuma turma pode ter aulas no mesmo horário que outra turma com alunos compartilhados.

O objetivo é determinar o menor número de horários necessários para alocar todas as turmas, garantindo que não haja sobreposição de horários para os alunos.

EX:

Na escola, há 6 turmas (A,B,C,D,E,F). As seguintes turmas compartilham alunos, criando conflitos:
Conflitos:
A compartilha alunos com B e C.
B compartilha alunos com C e D.
C compartilha alunos com E.
D compartilha alunos com E e F.

Saída esperada: 

Uma solução ótima distribui as turmas da seguinte maneira:
Horário 1 (Vermelho): Turmas A e D
Horário 2 (Azul): Turmas B e E
Horário 3 (Verde): Turmas C e F

Algoritimo testado em:
* Windows 11

Compilador:
* Code::Blocks
* Visual Studio Code
