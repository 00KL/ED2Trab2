#include "abb.h"

//arvore test <6 <2 <1 < > < > > <4 <3 < > < > > < > > <8 < > < > > >

int bestFit(int N, int* vet){
    arv* arvore = cria_vazia();

    for(int i = 0; i < N; i++){
        arvore = insercao(arvore, vet[i]);
    }

    int retorno = quantDisco(arvore);
    libera(arvore);
    return retorno;

}
