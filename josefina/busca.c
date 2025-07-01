#include <stdio.h>
#include <stdlib.h>
#define tamanho 100
#include "busca.h"
#include "fila.h"
#include "funcao.h"
#include "grafo.h"

void buscaLargura(Grafo *grafo, int v, int visitou[], int ref[], int quant){
    for(int i=0;i<quant;i++){
        visitou[i] = -1;
        ref[i] = -1;
    }

    Fila *fila = criarFila();
    if(fila==NULL){
        printf("Erro na criacao da fila!\n");
    }

    inserirElemento(fila, v);
    visitou[v-1]= 0;

    while(!estaVazia(fila)){
        int x = remover(fila);
        NoLista *aux = grafo->proximo[x-1];

        while(aux!=NULL){
            int y = aux->valor;
            if(visitou[y-1]==-1){
                inserirElemento(fila,y);
                visitou[y-1] = visitou[x-1]+1;
                ref[y-1] = x;
            }
            aux=aux->next;
        }
    }
    liberarFila(fila);
}
