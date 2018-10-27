#include "PQ.h"

void worstFit(int N, int* vet){
    //Cria heap
    PQ* pq = initPQ(N);

    for(int i = 0; i < N; i++){
        //retira um disco para atualização
        Item atual = deletaItem(pq);

        //Caso vet[i] n caiba no disco com maior espaço disponivel
        //deve-se criar um novo disco e devolver o anterior
        int aux = alteraDisco(atual, vet[i]);
        if( aux < 0){
            inserePQ(pq, atual);
            inserePQ(pq, novoDisco(vet[i]) );
        }else{
            //caso o novo montante de dados caiba basta atualizaro disco
            inserePQ(pq, aux);
        }
    }

    printf("Número de discos em uso: %d\n", tamPq(pq));
}

void sort(int N, int* vet){
    //Cria heap
    PQ* pq = initPQ(N);

    for(int i = 0; i < N; i++){
        //retira um disco para atualização
        printf("[%d] \n", vet[i]);
        inserePQ(pq, vet[i]);
    }

    //printHeap(pq);

    for(int i = 0; i < N; i++){
        printf("%d \n", deletaItem(pq));
    }

    //printf("Número de discos em uso: %d\n", tamPq(pq));
}
