#include "worstFit/PQ.h"
#include "bestFit/abb.h"

int main(int argc, char *argv[ ]){
    //quantidade de componentes
    int N;
    FILE* arq = fopen(argv[1], "r");
    if(arq == NULL){
        printf("ERRO: Arquivo não encontrado.\n\n");
        return 0;
    }

    //leitura de todas as entradas
    int* vet = (int*)malloc(sizeof(int)*N);
    fscanf(arq, "%d", &N);
    for(int i = 0; i < N; i++){
        fscanf(arq,"%d", &vet[i]);
    }

    // for(int i = 0; i < N; i++){
    //     printf("%d\n", vet[i] );
    // }
    //
    // printf("\n\n");

    //worstFit(N, vet);
    bestFit(N, vet);



}
