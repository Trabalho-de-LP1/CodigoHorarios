#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int turma1;
    int turma2;
}Turmas; //classe para colocar as duas colunas de turmas pra comparar dps

Turmas* ler_arquivo(const char* nomeArquivo, int* numTurmas, int* numConflitos){
    FILE* arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("erro ao importar arquivo");
        exit(1);
    }

    char p[5], edge[5]; //define so pra q ele le se no codigo e não contasse
    fscanf(arquivo, "%s %s %d %d", p, edge, numTurmas, numConflitos);
    Turmas* turmas = (Turmas*) malloc((*numConflitos) * sizeof(Turmas)); //cria um vetor do tamanho da classe
    if(turmas == NULL){
        printf("erro de alocacao");
        exit(1);
    }

    for(int i=0; i<*numConflitos; i++){
        char e;
        fscanf(arquivo, " %c %d %d", &e, &turmas[i].turma1, &turmas[i].turma2); //atribui os numeros la para cada objeto do struct
    }

    fclose(arquivo);
    return turmas;
}

int** criarGrafo(int numTurmas){
    int** grafo = (int**) malloc(numTurmas * sizeof(int*)); //cria uma matriz
    for(int i=0; i<numTurmas; i++){
        grafo[i] = (int*) malloc(numTurmas * sizeof(int)); //cria os espaços pra dentro da matriz
        for(int j=0; j<numTurmas; j++){
            grafo[i][j] = 0; //coloca 0 para elemento dentro da matriz
        }
    }
    return grafo;
}

void preencherGrafo(int** grafo, Turmas* conflitos, int numConflitos){
    for(int i=0; i<numConflitos; i++){
        int u = conflitos[i].turma1 - 1;
        int v = conflitos[i].turma2 - 1;
        grafo[u][v] = 1;
        grafo[v][u] = 1;
    }
}

int* colorirGrafo(int** grafo, int numTurmas){
    int* cores = (int*) malloc(numTurmas * sizeof(int)); //cria um vetor pra colocar as cores
    if(cores == NULL){
        printf("erro de alocacao");
        exit(1);
    }

    for(int i=0; i<numTurmas; i++){
        cores[i] = -1; //todos começam sem cor, no caso -1
    }

    cores[0] = 0; //o primeiro vai começar com 0

    int* coresDisponiveis = (int*) malloc(numTurmas * sizeof(int)); //vetor pra cores disponiveis
    for(int j=1; j<numTurmas; j++){
        for(int k=0; k<numTurmas; k++){
                coresDisponiveis[k] = 1; //todos vão começar com 1
        }
        for(int l=0; l<numTurmas; l++){
            if(grafo[j][l] == 1 && cores[l] != -1){
                coresDisponiveis[cores[l]] = 0; //se uma turma ainda não foi atribuida cor, então ela passa a ser 0
            }
        }

        int cor;
        for(cor=0; cor<numTurmas; cor++){
            if(coresDisponiveis[cor] == 1){
                break;
            }
        }
        cores[j] = cor; //se houver uma cor disponivel, ele vai atribuir ela
    }

    free(coresDisponiveis);
    return cores;
}

void horarios(int** grafo, int numTurmas){
    FILE* arq = fopen("Horarios.txt", "w"); //cria o arquivo q ele pediu pra colocar os horarios
    if(arq == NULL){
        printf("erro ao criar arquivo");
        exit(1);
    }

    int* horario = colorirGrafo(grafo, numTurmas); //chama a funçao pra preencher o grafo pra ele ser printado dps

    int maxCor = 0;
    for (int j = 0; j < numTurmas; j++){
        if (horario[j] > maxCor){maxCor = horario[j];} //vai pegar o maximo de cores, ou seja, o minimo de horarios
    }

    for (int i = 0; i <= maxCor; i++){
        fprintf(arq, "Horario %d: Turma/s ", i+1); //atribui as quantidades de horarios

        int primeira = 1;
        for(int j=0; j<numTurmas; j++){
            if(horario[j] == i){
                if(!primeira){
                    fprintf(arq, " e "); //um e entre as salas, so para separar melhor elas
                }
                fprintf(arq, "%d", j+1); //escreve quais salas estao naquele horario
                primeira = 0;
            }
        }
        fprintf(arq, "\n"); //pula pra proxima linha
    }

    fprintf(arq, "\nMenor numero de horarios necessario: %d\n", maxCor+1); //retorna o numero minimo de horarios

    free(horario);
    fclose(arq);
}

void liberarGrafo(int** grafo, int numTurmas){
    for(int i=0; i<numTurmas; i++){
        free(grafo[i]); //funçao pra liberar a memoria usada, pra tornar ele mais eficiente
    }
    free(grafo);
}

int main()
{
    int turmas, numConflitos;
    Turmas* conflitos = ler_arquivo("testeH6.txt", &turmas, &numConflitos);  //esse foi so um arquivo de teste q eu coloquei

    int** grafo = criarGrafo(turmas);
    preencherGrafo(grafo, conflitos, numConflitos);

    horarios(grafo, turmas);  //chama as funçoes necessarias

    free(conflitos);
    liberarGrafo(grafo, turmas);  //libera o espaço usado pelo grafo e pelo arquivo de teste
    return 0;
}
