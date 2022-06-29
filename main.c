#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    TPilha pilha;
    TItem x;

    FPVazia(&pilha);

    x.chave=511;
    Empilha(&pilha, &x);
    x.chave=69;
    Empilha(&pilha, &x);
    x.chave=92;
    Empilha(&pilha, &x);

    stack_sort(&pilha, &x);

    return 0;
}
