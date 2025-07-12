#include <stdio.h>
#include <stdlib.h>
#include "../header/IO.h"
#include "../header/colorir.h"
#define import fopen

union dado{
    char palavra[10];
    char letra;
};

// Lê o arquivo de entrada
Turmas* ler_arquivo(const char* nomeArquivo, int* numTurmas, int* numConflitos) {
    union dado p, edge, e;
    

    FILE* arquivo = import(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao importar arquivo\n");
        exit(1);
    }

    p.palavra, edge.palavra;
    fscanf(arquivo, "%s %s %d %d", p.palavra, edge.palavra, numTurmas, numConflitos);

    Turmas* turmas = (Turmas*) malloc((*numConflitos) * sizeof(Turmas));
    if (turmas == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }

    for (int i = 0; i < *numConflitos; i++) {
        e.letra;
        fscanf(arquivo, " %c %d %d", &e.letra, &turmas[i].turma1, &turmas[i].turma2);
    }

    fclose(arquivo);
    return turmas;
}

// Gera arquivo com horários agrupados
void horarios(int** grafo, int numTurmas) {
    FILE* arq = import("Horarios.txt", "w");
    if (arq == NULL) {
        printf("Erro ao criar arquivo\n");
        exit(1);
    }

    int* horario = colorirGrafo(grafo, numTurmas);
    
    int maxCor = 0;
    for (int j = 0; j < numTurmas; j++) {
        if (horario[j] > maxCor){
            maxCor = horario[j];}
    }

    for (int i = 0; i <= maxCor; i++) {
        fprintf(arq, "Horário %d: Turmas ", i + 1);

        int primeira = 1;
        for (int j = 0; j < numTurmas; j++) {
            if (horario[j] == i) {
                if (!primeira) {
                    fprintf(arq, " e ");}
                fprintf(arq, "%d", j + 1);
                primeira = 0;
            }
        }
        fprintf(arq, "\n");
    }

    fprintf(arq, "\nMenor número de horários necessário: %d\n", maxCor + 1);

    free(horario);
    fclose(arq);
}