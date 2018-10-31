#include "PQ.h"

int worstFit(int N, int* vet){
    //Cria heap
    PQ* pq = initPQ(N);

    for(int i = 0; i < N; i++){

        if( (pegaMax(pq) - vet[i]) < 0 ){
            inserePQ(pq, novoDisco(vet[i]));
        }else{
            Item aux = deletaItem(pq);
            aux = alteraDisco(aux, vet[i]);
            inserePQ(pq, aux);
        }
    }


    return tamPq(pq);
}


void sort(int N, int* vet){
    //Cria heap
    PQ* pq = initPQ(N);

    for(int i = 0; i < N; i++){
        //retira um disco para atualização
        //printf("[%d] \n", vet[i]);
        inserePQ(pq, vet[i]);
    }

    //printHeap(pq);

    for(int i = 0; i < N; i++){
        vet[i] = deletaItem(pq);
    }

}
