#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "colorir.h"

Turmas* ler_arquivo(const char* nomeArquivo, int* numTurmas, int* numConflitos) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao importar arquivo\n");
        exit(1);
    }

    char p[5], edge[5];
    fscanf(arquivo, "%s %s %d %d", p, edge, numTurmas, numConflitos);
    Turmas* turmas = (Turmas*) malloc((*numConflitos) * sizeof(Turmas));
    if (turmas == NULL) {
        printf("Erro de alocacao\n");
        exit(1);
    }

    for (int i = 0; i < *numConflitos; i++) {
        char e;
        fscanf(arquivo, " %c %d %d", &e, &turmas[i].turma1, &turmas[i].turma2);
    }

    fclose(arquivo);
    return turmas;
}

void horarios(int** grafo, int numTurmas) {
    FILE* arq = fopen("Horarios.txt", "w");
    if (arq == NULL) {
        printf("Erro ao criar arquivo\n");
        exit(1);
    }

    int* horario = colorirGrafo(grafo, numTurmas);

    int maxCor = 0;
    for (int j = 0; j < numTurmas; j++) {
        if (horario[j] > maxCor) { maxCor = horario[j]; }
    }

    for (int i = 0; i <= maxCor; i++) {
        fprintf(arq, "Horario %d: Turmas ", i + 1);

        int primeira = 1;
        for (int j = 0; j < numTurmas; j++) {
            if (horario[j] == i) {
                if (!primeira) {
                    fprintf(arq, " e ");
                }
                fprintf(arq, "%d", j + 1);
                primeira = 0;
            }
        }
        fprintf(arq, "\n");
    }

    fprintf(arq, "\nMenor numero de horarios necessario: %d\n", maxCor + 1);

    free(horario);
    fclose(arq);
}
