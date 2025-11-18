#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
int main() {
    HEAP heap;
    criar(&heap);

    int valor;
    
        
        while (1) {
            printf("Digite valores para inserir (digite -1 para parar e ver o formato do heap): \n");
            printf("> ");
            scanf("%d", &valor);
            if (valor == -1) break;
            inserir_valor(&heap, valor);
          // mostra o heap após cada inserção
        }
        imprimir_heap(&heap);
    
    return 0;
}
