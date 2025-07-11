#ifndef IO_H
#define IO_H

typedef struct {
    int turma1;
    int turma2;
} Turmas; // Guarda pares de conflito

Turmas* ler_arquivo(const char* nomeArquivo, int* numTurmas, int* numConflitos); // Lê arquivo de entrada
void horarios(int** grafo, int numTurmas); // Resolve coloração e grava arquivo de saída

#endif
