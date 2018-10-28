#include <stdio.h>
#include <stdlib.h>
#include "../item.h"

//Defines
#define Giga 1000000;

typedef struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
}arv;

void libera(arv*);

//pronta
arv* cria_vazia();
void imprime_crescente(arv*);
arv* insereAbb(arv*, int );
int busca(arv*, int);
arv* retira(arv*, int);
arv* retira_aux(arv* , int );//auxliar

//fit
void bestFit(int , int*);

//boooooora
arv* insereDados(arv* , int);
arv* insercao(arv* , int );
arv* reestrutura(arv*);
int quantDisco(arv*);
arv* buscaBestFit(arv*, int);
