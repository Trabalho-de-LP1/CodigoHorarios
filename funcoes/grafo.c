#include <stdlib.h>
#include "../header/grafo.h"

int** criarGrafo(int numTurmas) {
    int** grafo = (int**) malloc(numTurmas * sizeof(int*));
    for (int i = 0; i < numTurmas; i++) {
        grafo[i] = (int*) malloc(numTurmas * sizeof(int));
        for (int j = 0; j < numTurmas; j++){
            grafo[i][j] = 0;}
    }
    return grafo;
}

void preencherGrafo(int** grafo, Turmas* conflitos, int numConflitos) {
    for (int i = 0; i < numConflitos; i++) {
        int u = conflitos[i].turma1 - 1;
        int v = conflitos[i].turma2 - 1;
        grafo[u][v] = 1;
        grafo[v][u] = 1;
    }
}

void liberarGrafo(int** grafo, int numTurmas) {
    for (int i = 0; i < numTurmas; i++){
        free(grafo[i]);}
    free(grafo);
}