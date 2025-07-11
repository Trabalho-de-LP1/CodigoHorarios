#include <stdio.h>
#include <stdlib.h>
#include "header/grafo.h"   // Funções do grafo
#include "header/IO.h"      // Funções de entrada/saída

int main(){
    int turmas, numConflitos;
    char arquivo[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", arquivo);  // Lê o nome do arquivo do usuário

    Turmas* conflitos = ler_arquivo(arquivo, &turmas, &numConflitos); // Lê dados do arquivo

    int** grafo = criarGrafo(turmas);            // Cria matriz de adjacência
    preencherGrafo(grafo, conflitos, numConflitos); // Preenche matriz com conflitos

    horarios(grafo, turmas);   // Faz coloração e salva resultado

    free(conflitos);           // Libera memória de conflitos
    liberarGrafo(grafo, turmas); // Libera memória do grafo
    return 0;
}