#include <stdio.h>
#include <stdlib.h>
#define tamanho 100

typedef struct noLista{
    int valor;
    struct noLista *next;
} NoLista;

NoLista *criarNo(int num){
    NoLista *no = (NoLista*)malloc(sizeof(NoLista));
    no->valor = num;
    no->next=NULL;
    return no;
}

typedef struct grafo{
    int vertices;
    NoLista **proximo;
} Grafo;

Grafo *criarGrafo(int ver){
    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->vertices = ver;
    grafo->proximo = (NoLista**)malloc(ver*sizeof(NoLista*)); //(NoLista**) é o cast. NoLista** é o ponteiro para um vetor de ponteiros para nós

    for(int i=0;i<ver;i++){
        grafo->proximo[i] = NULL; //grafo->próximo[i] é válido, pois grafo->próximo é um vetor de ponteiros
    }
    return grafo;
}

void inserirNo(Grafo *grafo, int v1, int v2){ //MULTIPLICAÇÃO POR 3 conferir
    NoLista *novo = criarNo(v2);
    novo->next = grafo->proximo[v1];
    grafo->proximo[v1] = novo;
}

int existeAresta(Grafo *grafo, int n1, int n2){
    NoLista *aux = grafo->proximo[n1];
    while(aux!=NULL){
        if(aux->valor == n2){
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

void imprimrirGrafo(Grafo *grafo){
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



int soma(int valor, int vet[], int quant){
    int soma;
    if(valor == 100){
        soma = 1;
    }
    else {
        soma = valor + 1;
    }

    for(int i=0;i<quant;i++){
        if(vet[i]==soma){
            return 0;
        }
    }
    return soma;
}

int subtracao(int valor, int vet[], int quant){
    int subtracao;
    if(valor == 1){
        subtracao=100;
    }
    else{
        subtracao = valor - 1;
    }

    for (int i=0; i<quant; i++){
        if(vet[i]==subtracao){
            return 0;
        }
    }
    return subtracao;
}

int multiplicacao2(int valor, int vet[], int quant){
    int mult2;
    if(valor>=51){
        return 0;
    }
    else{
        mult2 = valor*2;
    }

    for (int i=0; i<quant; i++){
        if(vet[i]==mult2){
            return 0;
        }
    }
    return mult2;
}

int multiplicacao3(int valor, int vet[], int quant){
    int mult3;
    if(valor>=34){
        return 0;
    }
    else{
        mult3 = valor*3;
    }
    for (int i=0; i<quant; i++){
        if(vet[i]==mult3){
            return 0;
        }
    }
    return mult3;
}

int divisao2(int valor, int vet[], int quant){
    int divisao;
    if(valor%2!=0){
        return 0;
    }
    else{
        divisao = valor/2;
    }

    for (int i=0; i<quant; i++){
        if(vet[i]==divisao){
            return 0;
        }
    }
    return divisao;
}

typedef struct nolista {
    float info;
    struct nolista *prox;
}Nolista;

typedef struct fila {
    Nolista *ini;
    Nolista *fim;
}Fila;

Fila *criarFila(){
    Fila *f=(Fila*)malloc(sizeof(Fila));
    if (f!=NULL){
        f->ini=NULL;
        f->fim=NULL;
        return f;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
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
        if (f->ini==NULL){ //1 elemento
            f->ini=NULL;
            f->fim=NULL;
        }
        else {
            f->ini=x->prox;
        }
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

int buscaLargura(Grafo *grafo, int v, int u, int visitou[], int quant){
    int cont=0;

    for(int i=0;i<quant;i++){
        visitou[i] = -1;
    }

    Fila *fila = criarFila();
    if(fila==NULL){
        printf("Erro na criacao da fila!\n");
        return -1;
    }

    visitou[v] = ++cont;
    inserirElemento(fila, v);
    if(v == u){
        return cont;
    }

    while(!estaVazia(&fila)){
        int x = remover(&fila);
        NoLista *aux = grafo->proximo[x];

        while(aux!=NULL){
            int y = aux->valor;
            if(visitou[y]==-1){
                inserirElemento(fila,y);
                visitou[y] = ++cont;

                if(y==u){
                    return cont;
                }
            }
            aux=aux->next;
        }
    }
    printf("\n");
}

int main()
{
    FILE *arq = fopen("Teste1.txt", "r");

    int atual, destino, quantCanaisProi;
    int i, j;

    fscanf(arq, "%d %d %d", &atual, &destino, &quantCanaisProi);

    printf("Canal atual: %d\n", atual);
    printf("Canal destino: %d\n", destino);
    printf("Quantidade canais proibidos: %d\n", quantCanaisProi);

    int vetor[tamanho];
    for(i=0;i<tamanho;i++){
        vetor[i]=i+1;
    }

    int vet[quantCanaisProi];
    int confirmacao;

    for(i=0;i<quantCanaisProi;i++){
        fscanf(arq, "%d", &vet[i]);
    }


    Grafo *grafo = criarGrafo(tamanho);
    //imprimrirGrafo(grafo);

    int retornoSoma=0;
    int retornoSub=0;
    int retornoM2=0;
    int retornoM3=0;
    int retornoDiv=0;
    int existe;

    for(i=0;i<tamanho;i++){
        confirmacao=0;
        for(j=0;j<quantCanaisProi;j++){
            if(vetor[i]==vet[j]){
                confirmacao=1;
            }
        }
        if(confirmacao==0){
            retornoSoma = soma(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoSoma);
            if(existe == 0){
                if(retornoSoma!=0){
                    inserirNo(grafo, vetor[i], retornoSoma);
                }
            }

            retornoSub = subtracao(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoSub);
            if(existe == 0){
                if(retornoSub!=0){
                    inserirNo(grafo, vetor[i], retornoSub);
                }
            }

            retornoM2 = multiplicacao2(vetor[i], vet, quantCanaisProi);
            printf("%d\n",retornoM2);
            existe = existeAresta(grafo, vetor[i], retornoM2);
            if(existe == 0){
                if(retornoM2!=0){
                    inserirNo(grafo, vetor[i], retornoM2);
                }
            }

            retornoM3 = multiplicacao3(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoM3);
            if(existe == 0){
                if(retornoM3!=0){
                    inserirNo(grafo, vetor[i], retornoM3);
                }
            }

            retornoDiv = divisao2(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoDiv);
            if(existe == 0){
                if(retornoDiv!=0){
                    inserirNo(grafo, vetor[i], retornoDiv);
                }
            }
        }
    }

    printf("teste\n");
    printf("oi\n");
    imprimrirGrafo(grafo);
    int cliques = buscaLargura(grafo, atual, destino, vetor, tamanho);
    if(cliques==-1){
        printf("Caminho nao encontrado!\n");
    }
    else{
        printf("O numero de cliques necessarios e %d\n", cliques);
    }



    fclose(arq);
    return 0;
}
