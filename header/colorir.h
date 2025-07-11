#ifndef COLORIR_H
#define COLORIR_H

// Faz coloração do grafo (busca solução ótima)
int* colorirGrafo(int** grafo, int numTurmas);

// Verifica se pode usar cor no vértice
int podeUsarCor(int** grafo, int* cores, int v, int cor, int numTurmas);

// Função recursiva de backtracking
int backtrackColorir(int** grafo, int numTurmas, int* cores, int vAtual, int maxCores);

#endif