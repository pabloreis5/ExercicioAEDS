#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
}TItem;

typedef struct Nodo{
    TItem item;
    struct Nodo* prox;
}TNodo;

typedef struct{
    TNodo *fundo;
    TNodo *topo;
    int tamanho;
}TPilha;

void FPVazia(TPilha *pPilha);
int PVazia(TPilha *pPilha);
int Empilha(TPilha *pPilha, TItem *pItem);
TItem Desempilha(TPilha *pPilha, TItem *pItem);
int DesempilhaMaior(TPilha *pPilha, TItem *pItem);
void stack_sort(TPilha *pPilha, TItem *pItem);









#endif
