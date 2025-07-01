#include <stdio.h>
#include <stdlib.h>
#define tamanho 100
#include "busca.h"
#include "fila.h"
#include "funcao.h"
#include "grafo.h"

Fila *criarFila(){
    Fila *f=(Fila*)malloc(sizeof(Fila));
    if (f!=NULL){
        f->ini=NULL;
        f->fim=NULL;
        return f;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
        return NULL;
    }
}

int estaVazia(Fila *f){
    if (f->ini==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirElemento(Fila *f, int v){
    Nolista *novo=(Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        novo->prox=NULL;
        if (!estaVazia(f)){
            f->fim->prox=novo;
            f->fim=novo;
        }
        else {
            f->ini=novo;
            f->fim=novo;
        }
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

int remover (Fila *f){
    if (!estaVazia(f)){
        Nolista *x=f->ini;
        int v;
        v= x->info;
        if(x->prox==NULL){
            f->fim=NULL;
        }
        f->ini=x->prox;
        free(x);
        return v;
    }
    else {
        return 0;
    }
}

void imprimir (Fila *f){
    if (!estaVazia(f)){
        Nolista *t;
        for (t=f->ini;t!=NULL;t=t->prox){
            printf ("%d\n", t->info);
        }
    }
    else {
        printf ("Fila vazia!\n");
    }
}

void liberarFila(Fila *f){
    if (!estaVazia(f)){
        Nolista *t;
        Nolista *temp;
        for (t=f->ini;t!=NULL;t=temp){
            temp=t->prox;
            free(t);
        }
        free(f);
    }
    else {
        free(f);
    }
}
