#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct {
    int chave;  
    int valor;
} ITEM;

typedef struct {
    ITEM itens[TAM];
    int fim;
} HEAP;

void criar(HEAP *h);
int vazia(HEAP *h);
int cheia(HEAP *h);
void bubbling_up(HEAP *h);
int inserir_valor(HEAP *h, int valor);
void bubbling_down(HEAP *h);
int remover(HEAP *h, ITEM *rem);
void imprimir_heap(HEAP *h);
