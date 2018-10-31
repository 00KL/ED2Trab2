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
    fscanf(arq, "%d", &N);
    int* vet = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        fscanf(arq,"%d", &vet[i]);
    }

    printf("%d\n", worstFit(N, vet));
    printf("%d\n", bestFit(N, vet));

    sort(N, vet);

    printf("%d\n", worstFit(N, vet));
    printf("%d\n", bestFit(N, vet));

    free(vet);
    fclose(arq);

}
