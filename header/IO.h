#ifndef IO_H
#define IO_H

typedef struct {
    int turma1;
    int turma2;
} Turmas; 

Turmas* ler_arquivo(const char* nomeArquivo, int* numTurmas, int* numConflitos); 
void horarios(int** grafo, int numTurmas); 

#endif
