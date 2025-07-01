#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct nolista {
    int info;
    struct nolista *prox;
}Nolista;

typedef struct fila {
    Nolista *ini;
    Nolista *fim;
}Fila;

Fila *criarFila();
int estaVazia(Fila *f);
void inserirElemento(Fila *f, int v);
int remover (Fila *f);
void imprimir (Fila *f);
void liberarFila(Fila *f);

#endif // FILA_H_INCLUDED
