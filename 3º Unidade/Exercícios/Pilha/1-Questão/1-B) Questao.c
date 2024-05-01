#include <stdio.h>
#include <stdlib.h>
#include "1-B) pilha.h"

struct lista{
    float vet;
    struct pilha *prox;
};

struct pilha {
    Lista *prim;
};

Pilha *pilha_cria(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push(Pilha *p, float valor){
    Lista *aux = (Lista*) malloc(sizeof(Lista));

    aux->vet = valor;
    aux->prox = p->prim;
    p->prim = aux;
}

float pilha_pop(Pilha *p){
    Lista *aux;
    float valor;

    if(pilha_vazia(p)){
        printf("Pilha vazia\n");
        exit(1);
    }

    aux = p->prim;
    valor = aux->vet;
    p->prim = aux->prox;
    free(aux);

    return valor;
}

int pilha_vazia(Pilha *p){
    return (p->prim ==NULL);
}

void pilha_libera(Pilha *p){
    Lista *aux= p->prim;
    Lista *aux2;

    while (aux != NULL) {
        aux2 = aux->prox;
        free(aux);
        aux = aux2;

    }

    free(p);
}
