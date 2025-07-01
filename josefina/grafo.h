#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct noLista{
    int valor;
    struct noLista *next;
} NoLista;

typedef struct grafo{
    int vertices;
    NoLista **proximo;
} Grafo;

NoLista *criarNo(int num);
Grafo *criarGrafo(int ver);
void inserirNo(Grafo *grafo, int v1, int v2);
int existeAresta(Grafo *grafo, int n1, int n2);
void imprimirGrafo(Grafo *grafo);
void imprimirCaminho(int refe[], int destino);
void liberarGrafo(Grafo *grafo);

#endif // GRAFO_H_INCLUDED
