#include <stdio.h>
#include <stdlib.h>
#include "item.h"

//Defines
#define Giga 1000000;

//struct
typedef struct pq{
    Item* vet;
    int ulti;
    int max;
}PQ;

PQ* initPQ(int N);

void fixDown(PQ* pq, int pai);

Item deletaItem(PQ* pq);

void fixUp(PQ* pq, int filho);

void insere(PQ* pq, Item disco);

void destruirHeap(PQ* pq);

int tamPq(PQ* pq);

Item alteraDisco(Item i, int alteracao);

Item novoDisco(int alteracao);

void printHeap(PQ* );

//fits
void worst(int N, int* vet);
void sort(int N, int* vet);
