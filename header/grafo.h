#ifndef GRAFO_H
#define GRAFO_H

#include "io.h"

int** criarGrafo(int numTurmas);
void preencherGrafo(int** grafo, Turmas* conflitos, int numConflitos);
void liberarGrafo(int** grafo, int numTurmas);

#endif
