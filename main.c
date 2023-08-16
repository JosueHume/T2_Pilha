#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct _pilha {
    int info[MAX];
    int topo;
} tp_pilha;

void push(tp_pilha *p, int value) {
    if (p->topo == MAX - 1) {
        printf("A pilha esta cheia. Nao e possivel inserir mais elementos.\n");
        return;
    }

    p->topo++;
    *(p->info+p->topo) = value;
    printf("Elemento %d inserido na pilha.\n", value);
}

void pop(tp_pilha *p) {
    if (p->topo == -1) {
        printf("A pilha esta vazia. Nao e possivel remover elementos.\n");
        return;
    }

    printf("Elemento %d removido da pilha.\n", *(p->info+p->topo);
    p->topo--;
}

void display(tp_pilha *p) {
    if (p->topo == -1) {
        printf("A pilha esta vazia.\n");
        return;
    }

    printf("Elementos da pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d\n", *(p->info+i);
    }
}

int main() {
    tp_pilha *p;
    int y, x;
    p = (tp_pilha *)malloc(sizeof(tp_pilha));
    p->topo = -1;

    do {
        printf("\nO que voce quer fazer com a pilha: Digite:\n\n 1=Inserir(push)\n 2=Retirar(pop)\n 3=Mostrar(display)\n 0=Sair\n\n");
        scanf("%d", &y);

        if (y == 1) {
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &x);
            push(p, x);
        } else if (y == 2) {
            pop(p);
        } else if (y == 3) {
            display(p);
        } else if (y == 0) {
            break;
        } else {
            printf("Esta opcao e invalida!\n");
        }
    } while (y != 0);

    printf("\nVoce optou por sair do programa. As operacoes foram finalizadas.\n");

    free(p);
}
