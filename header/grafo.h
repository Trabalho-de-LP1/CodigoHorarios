#ifndef GRAFO_H
#define GRAFO_H

#include "io.h"

int** criarGrafo(int numTurmas);            // Cria matriz de adjacência
void preencherGrafo(int** grafo, Turmas* conflitos, int numConflitos); // Marca arestas
void liberarGrafo(int** grafo, int numTurmas); // Libera matriz

#endif