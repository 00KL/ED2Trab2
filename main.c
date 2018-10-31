#include "worstFit/PQ.h"
#include "bestFit/abb.h"

int main(int argc, char *argv[ ]){
    //tentativa de abrir o arquivo
    FILE* arq = fopen(argv[1], "r");
    if(arq == NULL){
        printf("ERRO: Arquivo não encontrado.\n\n");
        return 0;
    }

    //quantidade de componentes
    int N;
    fscanf(arq, "%d", &N);
    //malloc para leitura de todas as entradas e leitura das mesmas
    int* vet = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        fscanf(arq,"%d", &vet[i]);
    }

    printf("%d\n", worstFit(N, vet));//worstFit
    printf("%d\n", bestFit(N, vet));//bestFit

    sort(N, vet);//ordenando usando heapsort

    printf("%d\n", worstFit(N, vet));//worstFit decrescente
    printf("%d\n", bestFit(N, vet));//bestfir decrescente

    //liberando memoria
    free(vet);
    fclose(arq);

}
