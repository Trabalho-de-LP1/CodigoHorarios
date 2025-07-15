#include <stdio.h>
#include <stdlib.h>
#include "../header/colorir.h"

int contaVertices(int n){
    if(n<=0){
        return 0;
    }else{
        return 1 + contaVertices(n-1);
    }
}

int* colorirGrafo(int** grafo, int numTurmas){
    int* cores = (int*) malloc(numTurmas * sizeof(int));
    int* grau = (int*) malloc(numTurmas * sizeof(int));
    int* ordem = (int*) malloc(numTurmas * sizeof(int));

    if(cores == NULL || grau == NULL || ordem == NULL){
        printf("erro ao alocar memoria em colorirGrafo\n");
        exit(1);
    }

    for (int i = 0; i < numTurmas; i++){
        grau[i] = 0;
        for (int j = 0; j < numTurmas; j++){
            if (grafo[i][j]){
                grau[i]++;}
        }
        cores[i] = -1;
        ordem[i] = i;
    }

    for (int i = 0; i < numTurmas - 1; i++){
        for (int j = i + 1; j < numTurmas; j++){
            if (grau[ordem[i]] < grau[ordem[j]]){
                int temp = ordem[i];
                ordem[i] = ordem[j];
                ordem[j] = temp;
            }
        }
    }

    printf("Total de vertices contados: %d", contaVertices(numTurmas));

    int numCores = 0;
    for (int i = 0; i < numTurmas; i++){
        int v = ordem[i];
        if (cores[v] == -1){
            cores[v] = numCores;
            for (int j = i + 1; j < numTurmas; j++){
                int u = ordem[j];
                if (cores[u] == -1){
                    int pode = 1;
                    for (int k = 0; k < numTurmas; k++){
                        if (grafo[u][k] && cores[k] == numCores){
                            pode = 0; 
                            break;
                        }
                    }
                    if (pode){
                        cores[u] = numCores;}
                }
            }
            numCores++;
        }
    }

    free(grau);
    free(ordem);
    return cores;
}