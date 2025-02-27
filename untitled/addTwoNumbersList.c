#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* adicionarNo(struct ListNode* lista, int val) {
    struct ListNode* novoNo = (struct ListNode*)malloc(sizeof(struct ListNode));
    novoNo->val = val;
    novoNo->next = NULL;

    if (lista == NULL) {
        return novoNo;
    }

    struct ListNode* temp = lista;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = novoNo;
    return lista;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* resultado = NULL;
    struct ListNode** p = &resultado;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int soma = carry;
        if (l1 != NULL) {
            soma += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            soma += l2->val;
            l2 = l2->next;
        }
        carry = soma / 10;
        soma = soma % 10;
        *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        (*p)->val = soma;
        (*p)->next = NULL;
        p = &((*p)->next);
    }
    return resultado;
}

void imprimirLista(struct ListNode* lista) {
    while (lista != NULL) {
        printf("%d ", lista->val);
        lista = lista->next;
    }
    printf("\n");
}

void liberarLista(struct ListNode* lista) {
    while (lista != NULL) {
        struct ListNode* temp = lista;
        lista = lista->next;
        printf("%d ", temp->val);
        free(temp);
    }
    printf("\n");
}

int main() {
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    l1 = adicionarNo(l1, 6);
    l1 = adicionarNo(l1, 4);
    l1 = adicionarNo(l1, 9);

    l2 = adicionarNo(l2, 1);
    l2 = adicionarNo(l2, 2);

    struct ListNode* resultado = addTwoNumbers(l1, l2);
    printf("Resultado: ");
    imprimirLista(resultado);
    liberarLista(l1);
    liberarLista(l2);
    liberarLista(resultado);
    return 0;
}
