#include <stdio.h>
#include <stdlib.h>
#define tamanho 100
#include "busca.h"
#include "fila.h"
#include "funcao.h"
#include "grafo.h"

int main()
{
    int atual=0, destino=0, quantCanaisProi=0;
    int i, j;

    scanf("%d %d %d", &atual, &destino, &quantCanaisProi);

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
        scanf("%d", &vet[i]);
    }

    Grafo *grafo = criarGrafo(tamanho);

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
                    inserirNo(grafo, vetor[i]-1, retornoSoma);
                }
            }

            retornoSub = subtracao(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoSub);
            if(existe == 0){
                if(retornoSub!=0){
                    inserirNo(grafo, vetor[i]-1, retornoSub);
                }
            }

            retornoM2 = multiplicacao2(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoM2);
            if(existe == 0){
                if(retornoM2!=0){
                    inserirNo(grafo, vetor[i]-1, retornoM2);
                }
            }

            retornoM3 = multiplicacao3(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoM3);
            if(existe == 0){
                if(retornoM3!=0){
                    inserirNo(grafo, vetor[i]-1, retornoM3);
                }
            }

            retornoDiv = divisao2(vetor[i], vet, quantCanaisProi);
            existe = existeAresta(grafo, vetor[i], retornoDiv);
            if(existe == 0){
                if(retornoDiv!=0){
                    inserirNo(grafo, vetor[i]-1, retornoDiv);
                }
            }
        }
    }

    int resultado[tamanho];
    int referencia[tamanho];
    buscaLargura(grafo, atual, resultado, referencia, tamanho);

    if(resultado[destino-1]!=-1){
        printf("Quantidade de cliques: %d\n", resultado[destino-1]);
    }
    else{
        printf("Nao e possivel chegar ate o canal desejado sem passar por canal adulto\n");
    }

    imprimirCaminho(referencia,destino);
    printf("\n");
    liberarGrafo(grafo);

    return 0;
}
