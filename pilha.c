#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void FPVazia(TPilha *pPilha){
    pPilha->topo=(TNodo*) malloc(sizeof(TNodo));
    pPilha->fundo = pPilha->topo;
    pPilha->topo->prox = NULL;
    pPilha->tamanho = 0;
}
int PVazia(TPilha *pPilha){
    return(pPilha->topo == pPilha->fundo);
}
int Empilha(TPilha *pPilha, TItem *pItem){
    TNodo *pNovo;

    pNovo = (TNodo*) malloc(sizeof(TNodo));
    pPilha->topo->item = *pItem;
    pNovo->prox = pPilha->topo;
    pPilha->topo = pNovo;
    pPilha->tamanho++;
    return 1;
}
TItem Desempilha(TPilha *pPilha, TItem *pItem){
    TNodo *pAux;
    pAux = NULL;

    if(PVazia(pPilha)){
        printf("Vazia");
        return pAux->item;
    }
    pAux = pPilha->topo;
    pPilha->topo = pAux->prox;
    *pItem = pAux->prox->item;
    TItem aux = *pItem;
    free(pAux);
    pPilha->tamanho--;
    return aux;
}

int DesempilhaMaior(TPilha *pPilha, TItem *pItem){
    TItem maior;
    TPilha pAux;

    FPVazia(&pAux);
    maior = Desempilha(pPilha, pItem);

    while(pPilha->tamanho != 0){
        TItem a = Desempilha(pPilha, pItem);
        if(a.chave > maior.chave){
            Empilha(&pAux, &maior);
            maior = a;
        }else{
            Empilha(&pAux, &a);
        }
    }
    *pPilha = pAux;


    return maior.chave;
}

void stack_sort(TPilha *pPilha, TItem *pItem){
    TItem maior;
    TPilha pAux;

    FPVazia(&pAux);
    while(pPilha->tamanho != 0){
        maior.chave = DesempilhaMaior(pPilha, pItem);
        Empilha(&pAux, &maior);
    }
    while(pAux.tamanho != 0){
        TItem a = Desempilha(&pAux, pItem);
        printf("%d\n", a.chave);
        Empilha(pPilha, &a);
    }
}


