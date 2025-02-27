#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 100

// Estrutura para um nó na tabela hash
typedef struct No {
    char* chave;
    int valor;
    struct No* proximo;
} No;

// Função de hash simples
unsigned int funcao_hash(char* chave) {
    unsigned int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash = 31 * hash + chave[i];
    }
    return hash % TAMANHO;
}

// Função para inserir um par chave-valor
void inserir(No** tabela, char* chave, int valor) {
    unsigned int indice = funcao_hash(chave);
    No* novo_no = malloc(sizeof(No));
    novo_no->chave = strdup(chave);
    novo_no->valor = valor;
    novo_no->proximo = tabela[indice];
    tabela[indice] = novo_no;
}

// Função para buscar um valor pela chave
int buscar(No** tabela, char* chave) {
    unsigned int indice = funcao_hash(chave);
    No* atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->valor;
        }
        atual = atual->proximo;
    }
    return -1; // Chave não encontrada
}

// Função para liberar a memória da tabela hash
void liberar(No** tabela) {
    for (int i = 0; i < TAMANHO; i++) {
        No* atual = tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp->chave);
            free(temp);
        }
    }
}

int main() {
    No* tabela[TAMANHO] = {NULL};

    inserir(tabela, "chave1", 42);
    inserir(tabela, "chave2", 84);

    printf("Valor associado a 'chave1': %d\n", buscar(tabela, "chave1"));
    printf("Valor associado a 'chave2': %d\n", buscar(tabela, "chave2"));

    liberar(tabela);
    return 0;
}
