#include "PQ.h"

int worstFit(int N, int* vet){
    //Cria heap
    PQ* pq = initPQ(N);

    //percorre o vetor de entrada colocando cada dado
    //na heap
    for(int i = 0; i < N; i++){

        //caso o maior valor da maxheap menos o valor
        //a ser acrescentado o novo valor n cabe e deve
        //ser adicionado junto com um novo disco
        if( (pegaMax(pq) - vet[i]) < 0 ){
            inserePQ(pq, novoDisco(vet[i]));
        }
        //caso contrario o valor cabe no item com mais expaço vazio
        else{
            //o maior valor deve ser retirado
            Item aux = deletaItem(pq);
            //atualizado
            aux = alteraDisco(aux, vet[i]);
            //e reinserido
            inserePQ(pq, aux);
        }
    }

    //guarda a quantidade de discos
    int quantDisco = tamPq(pq);
    //libera estrutura da heap
    destruirHeap(pq);
    //retorna quantidade de disco
    return quantDisco;
}


void sort(int N, int* vet){
    //Cria heap
    PQ* pq = initPQ(N);

    //insere todos os valores na heap
    for(int i = 0; i < N; i++){
        inserePQ(pq, vet[i]);
    }

    //retira os valores do maior para o menor
    //gerando uma ordem decrescente
    for(int i = 0; i < N; i++){
        vet[i] = deletaItem(pq);
    }

    //libera expaço ocupado pela heap
    destruirHeap(pq);

}
