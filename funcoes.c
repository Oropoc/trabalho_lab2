#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void criar(HEAP *h) {
    h->fim = -1;
}

int vazia(HEAP *h) {
    return h->fim == -1;
}

int cheia(HEAP *h) {
    return h->fim == TAM - 1;
}

void bubbling_up(HEAP *h) {
    int i = h->fim;
    int pai = (i - 1) / 2;

    while (i > 0 && h->itens[i].chave > h->itens[pai].chave) {
        ITEM tmp = h->itens[i];
        h->itens[i] = h->itens[pai];
        h->itens[pai] = tmp;

        i = pai;
        pai = (pai - 1) / 2;
    }
}

int inserir_valor(HEAP *h, int valor) {
    if (cheia(h)) return 0;

    h->fim++;

    h->itens[h->fim].valor = valor;
    h->itens[h->fim].chave = valor;  // chave automática = valor

    bubbling_up(h);
    return 1;
}

void bubbling_down(HEAP *h) {
    int i = 0;

    while (i <= h->fim / 2) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int maior = esq;

        if (dir <= h->fim && h->itens[dir].chave > h->itens[esq].chave)
            maior = dir;

        if (h->itens[i].chave >= h->itens[maior].chave) break;

        ITEM tmp = h->itens[i];
        h->itens[i] = h->itens[maior];
        h->itens[maior] = tmp;

        i = maior;
    }
}

int remover(HEAP *h, ITEM *rem) {
    if (vazia(h)) return 0;

    *rem = h->itens[0];

    h->itens[0] = h->itens[h->fim];
    h->fim--;

    bubbling_down(h);

    return 1;
}


void imprimir_heap(HEAP *h) {
    printf("\n===== REPRESENTACAO DO HEAP =====\n");

    for (int i = 0; i <= h->fim; i++) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        printf("\nNo [%d] = %d", i, h->itens[i].valor);

        if (i == 0)
            printf(" (raiz)");

        if (esq <= h->fim)
            printf("\n  Filho esquerdo: %d", h->itens[esq].valor);
        else
            printf("\n  Filho esquerdo: (nenhum)");

        if (dir <= h->fim)
            printf("\n  Filho direito: %d\n", h->itens[dir].valor);
        else
            printf("\n  Filho direito: (nenhum)\n");
    }

    printf("=================================\n\n");
}