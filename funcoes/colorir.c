#include <stdlib.h>
#include <stdio.h>
#include "../header/colorir.h"

// Checa se cor é válida para o vértice v
int podeUsarCor(int** grafo, int* cores, int v, int cor, int numTurmas) {
    for (int i = 0; i < numTurmas; i++) {
        if (grafo[v][i] && cores[i] == cor) {
            return 0; // Cor já usada por vizinho
        }
    }
    return 1; // Pode usar cor
}

// Função recursiva: tenta colorir todos os vértices
int backtrackColorir(int** grafo, int numTurmas, int* cores, int vAtual, int maxCores) {
    if (vAtual == numTurmas){
        return 1;} // Todos coloridos

    for (int cor = 0; cor < maxCores; cor++) {
        if (podeUsarCor(grafo, cores, vAtual, cor, numTurmas)) {
            cores[vAtual] = cor; // Atribui cor
            if (backtrackColorir(grafo, numTurmas, cores, vAtual + 1, maxCores)){
                return 1;} // Sucesso
            cores[vAtual] = -1; // Desfaz (backtrack)
        }
    }
    return 0; // Falhou
}

// Tenta coloração ótima (mínimo de cores)
int* colorirGrafo(int** grafo, int numTurmas) {
    int* cores = (int*) malloc(numTurmas * sizeof(int));
    if (cores == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }

    for (int i = 0; i < numTurmas; i++) cores[i] = -1;

    for (int maxCores = 1; maxCores <= numTurmas; maxCores++) {
        if (backtrackColorir(grafo, numTurmas, cores, 0, maxCores)){
        break;}
    }

    return cores;
}