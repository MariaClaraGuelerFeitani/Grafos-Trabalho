#include <stdio.h>
#include <stdlib.h>
#define tamanho 100
#include "busca.h"
#include "fila.h"
#include "funcao.h"
#include "grafo.h"

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
