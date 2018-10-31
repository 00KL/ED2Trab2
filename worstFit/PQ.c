#include "PQ.h"

//inicia a estrutura heap
PQ* initPQ(int N){
    PQ* pq = (PQ*)malloc(sizeof(PQ));
    pq->vet = (Item*)malloc(sizeof(Item*)* (N+1));
    pq->ulti = 0;

    return pq;
}

//reorganiza os elemento da heap de cima pra baixo
void fixDown(PQ* pq, int pai){
    //testa os valores ate que o indice pai*2(proximo filho)
    //seja menor que o ultimo indice possivel (pq->ulti)
    while(pai*2 <= pq->ulti ){

        //atualiza valor para o filho atual
        int filho = pai*2;
        //se pergunta se no atual pode ter dois filhos se perguntando se o
        //primeiro filho é o ultimo elemento do vetor ou n;
        //caso o filho da direita seja maior q o da esquerda ele deve
        //ser o filho a ser comparado com o pai
        if( filho < pq->ulti && pq->vet[filho] < pq->vet[filho + 1]){
            filho++;
        }
        //caso o filho seja menor q o pai a função deve parar
        if(pq->vet[filho] < pq->vet[pai]){
            return;
        }
        //troca o filho com o pai
        exch(pq->vet[filho], pq->vet[pai]);

        //atualiza o pai
        pai = filho;
    }
}

Item deletaItem(PQ* pq){
    //se a heap for vazia um disco vazio é retornado
    if(pq->ulti == 0) return Giga;

    //troca o ultimo com o primeiro
    exch(pq->vet[1], pq->vet[pq->ulti]);
    //guarda o valor do ultimo elemento
    Item retirado = pq->vet[pq->ulti];
    //decresce a quantidade elementos
    //recalculando o ultimo elemento
    pq->ulti--;

    //reorganiza a arvore descendo a nova raiz para seu lugar
    //devido
    fixDown(pq, 1);

    //retorna maior elemento da heap
    return retirado;
}

//reestrutura a arvore de baixo para cima
void fixUp(PQ* pq, int filho){
    //cria pai disco atual
    int pai = filho/2;

    //testa os valores enquanto o indice filho for
    //menor que a raiz, pois a raiz n é filho de
    //ninguem. E enquanto o pai for menor que o filho.
    while(1 < filho && pq->vet[pai] < pq->vet[filho] ){
        //troca o filho e o pai de lugar
        exch(pq->vet[pai], pq->vet[filho]);
        //atualiza indices
        filho = pai;
        pai = filho/2;
    }
}

void inserePQ(PQ* pq, Item disco){
    //cresce quantidade de elementos da lista
    //mudando o indice do ultimo valor
    pq->ulti++;
    //acrescenta novo disco na ultima posição
    pq->vet[pq->ulti] = disco;
    //reestrutura arvore para posicionar corretamente novo disco
    fixUp(pq, pq->ulti);

}

//libera estrutura da arvore
void destruirHeap(PQ* pq){
    free(pq->vet);
    free(pq);
}

//retorna quantidade de elemento da heap
int tamPq(PQ* pq){
    return pq->ulti;
}

//atualiza valor do disco
Item alteraDisco(Item i, int alteracao){
    return i - alteracao;
}

//cria novo disco
Item novoDisco(int alteracao){
    int saida = Giga;
    saida -= alteracao;
    return saida;
}

//printa a heap
void printHeap(PQ* pq){
    for(int i = 1; i <= pq->ulti; i++){
        printf("[%d] ", pq->vet[i]);
    }

    printf("\n\n" );

}

// retorna o maior valor da heap
int pegaMax(PQ* pq){
    if(pq->ulti == 0) return -1;
    return pq->vet[1];
}
