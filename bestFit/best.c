#include "abb.h"

//arvore test <6 <2 <1 < > < > > <4 <3 < > < > > < > > <8 < > < > > >

int bestFit(int N, int* vet){
    arv* arvore = cria_vazia();

    for(int i = 0; i < N; i++){
        //printf("[%d]\n", vet[i]);
        arvore = insercao(arvore, vet[i]);
        //imprime_crescente(arvore);
        //printf("\n\n" );
    }

    int retorno = quantDisco(arvore);
    libera(arvore);
    return retorno;

}
