#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "grafo.h"

int main() {
    int turmas, numConflitos;
    char arquivo[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", arquivo);

    Turmas* conflitos = ler_arquivo(arquivo, &turmas, &numConflitos);

    int** grafo = criarGrafo(turmas);
    preencherGrafo(grafo, conflitos, numConflitos);

    horarios(grafo, turmas);

    free(conflitos);
    liberarGrafo(grafo, turmas);
    return 0;
}
