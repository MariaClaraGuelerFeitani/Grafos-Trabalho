#include <stdio.h>
#include <stdlib.h>
#define tamanho 100
#include "busca.h"
#include "fila.h"
#include "funcao.h"
#include "grafo.h"

NoLista *criarNo(int num){
    NoLista *no = (NoLista*)malloc(sizeof(NoLista));
    no->valor = num;
    no->next=NULL;
    return no;
}

Grafo *criarGrafo(int ver){
    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->vertices = ver;
    grafo->proximo = (NoLista**)malloc(ver*sizeof(NoLista*)); //(NoLista**) é o cast. NoLista** é o ponteiro para um vetor de ponteiros para nós

    for(int i=0;i<ver;i++){
        grafo->proximo[i] = NULL; //grafo->próximo[i] é válido, pois grafo->próximo é um vetor de ponteiros
    }
    return grafo;
}

void inserirNo(Grafo *grafo, int v1, int v2){
    NoLista *novo = criarNo(v2);
    novo->next = grafo->proximo[v1];
    grafo->proximo[v1] = novo;
}

int existeAresta(Grafo *grafo, int n1, int n2){
    NoLista *aux = grafo->proximo[n1-1];
    while(aux!=NULL){
        if(aux->valor == n2){
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

void imprimirGrafo(Grafo *grafo){
    for(int i=0;i<grafo->vertices;i++){
        NoLista *aux = grafo->proximo[i];
        printf("Vertice %d: ", i+1);
        while(aux){
            printf(" %d -> ", aux->valor);
            aux = aux->next;
        }
        printf("\n");
    }
}

void imprimirCaminho(int refe[], int destino) {
    if (refe[destino-1] == -1) {
        printf("%d", destino);
        return;
    }
    imprimirCaminho(refe, refe[destino-1]);
    printf(" -> %d", destino);
}

void liberarGrafo(Grafo *grafo) {
    if (grafo != NULL) {
        for (int i = 0; i < grafo->vertices; i++) {
            NoLista *aux = grafo->proximo[i];
            while (aux != NULL) {
                NoLista *temp = aux;
                aux = aux->next;
                free(temp);
            }
        }
        free(grafo->proximo);
        free(grafo);
    }
}
