#include <stdlib.h>
#include <stdio.h>
#include "colorir.h"

int podeUsarCor(int** grafo, int* cores, int v, int cor, int numTurmas) {
    for (int i = 0; i < numTurmas; i++) {
        if (grafo[v][i] && cores[i] == cor) {
            return 0;
        }
    }
    return 1;
}

int backtrackColorir(int** grafo, int numTurmas, int* cores, int vAtual, int maxCores) {
    if (vAtual == numTurmas) return 1;

    for (int cor = 0; cor < maxCores; cor++) {
        if (podeUsarCor(grafo, cores, vAtual, cor, numTurmas)) {
            cores[vAtual] = cor;
            if (backtrackColorir(grafo, numTurmas, cores, vAtual + 1, maxCores)) {
                return 1;
            }
            cores[vAtual] = -1;
        }
    }
    return 0;
}

int* colorirGrafo(int** grafo, int numTurmas) {
    int* cores = (int*) malloc(numTurmas * sizeof(int));
    if (cores == NULL) {
        printf("Erro de alocacao\n");
        exit(1);
    }

    for (int i = 0; i < numTurmas; i++) {
        cores[i] = -1;
    }

    int maxCores;
    for (maxCores = 1; maxCores <= numTurmas; maxCores++) {
        if (backtrackColorir(grafo, numTurmas, cores, 0, maxCores)) {
            break;
        }
    }

    return cores;
}
