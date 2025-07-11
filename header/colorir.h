#ifndef COLORIR_H
#define COLORIR_H

int* colorirGrafo(int** grafo, int numTurmas);
int podeUsarCor(int** grafo, int* cores, int v, int cor, int numTurmas);
int backtrackColorir(int** grafo, int numTurmas, int* cores, int vAtual, int maxCores);

#endif
