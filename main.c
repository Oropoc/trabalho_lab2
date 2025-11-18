// ...existing code...
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    HEAP heap;
    criar(&heap);

    int op, valor;
    ITEM rem;

    while (1) {
        printf("\nMenu:\n");
        printf("1 - Inserir no heap\n");
        printf("2 - Remover (maior)\n");
        printf("3 - Ver heap\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("Valor a inserir: ");
                scanf("%d", &valor);
                if (valor <= 0){
                    printf("Entrada inválida.\n");
                    break;
                }
                if (!inserir_valor(&heap, valor))
                    printf("Heap cheio.\n");
                else
                    printf("Inserido: %d\n", valor);
                break;
            case 2:
                if (remover(&heap, &rem))
                    printf("Removido: %d\n", rem.valor);
                else
                    printf("Heap vazio.\n");
                break;
            case 3:
                imprimir_heap(&heap);
                break;
            case 0:
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}

