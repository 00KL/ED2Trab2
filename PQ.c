#include "PQ.h"

PQ* initPQ(int N){
    PQ* pq = (PQ*)malloc(sizeof(PQ));
    pq->vet = (Item*)malloc(sizeof(Item*)* (N+1));
    pq->ulti = 0;

    return pq;
}

void fixDown(PQ* pq, int index){
    while(2*index <= pq->ulti){
       int l = 2*index;

       if(l < pq->ulti && pq->vet[l] < pq->vet[l+1]) l++;

       if(!less(pq->vet[index],pq->vet[l])) break;

       exch(pq->vet[l],pq->vet[index]);
       index = l;
   }
}

Item deletaItem(PQ* pq){
    //se a heap for vazia um disco criado
    if(pq->ulti == 0) return Giga;

    exch(pq->vet[1], pq->vet[pq->ulti]);
    Item retirado = pq->vet[pq->ulti];
    pq->ulti--;

    fixDown(pq, 1);
    return retirado;
}

void fixUp(PQ* pq, int filho){
    int pai = filho/2;
    while(1 < filho && pq->vet[pai] < pq->vet[filho] ){
        exch(pq->vet[pai], pq->vet[filho]);
        filho = pai;
        pai = filho/2;
    }
}

void inserePQ(PQ* pq, Item disco){
    pq->ulti++;
    pq->vet[pq->ulti] = disco;

    fixUp(pq, pq->ulti);

}

void destruirHeap(PQ* pq){
    free(pq->vet);
    free(pq);
}

int tamPq(PQ* pq){
    return pq->ulti;
}

Item alteraDisco(Item i, int alteracao){
    return i - alteracao;
}

Item novoDisco(int alteracao){
    int saida = Giga;
    saida -= alteracao;
    return saida;
}

void printHeap(PQ* pq){
    for(int i = 1; i <= pq->ulti; i++){
        printf("%d\n", pq->vet[i]);
    }

    printf("\n\n" );

}

//tests
int pegaMax(PQ* pq){
    if(pq->ulti == 0) return -1;
    return pq->vet[1];
}
