#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 3  // Tamanho inicial da pilha

int *pilha;  // Ponteiro para o array da pilha
int topo = -1;  // Índice do topo da pilha
int capacidade = INITIAL_SIZE;  // Capacidade atual da pilha

// Função para inserir um elemento na pilha (push)
void push(int elemento) {
    if (topo < capacidade - 1) {  // Verifica se ainda há espaço na pilha
        pilha[++topo] = elemento;  // Incrementa o topo e insere o elemento
    } else {
        printf("Capacidade da pilha atingida. Expandindo...\n");
        capacidade *= 2;  // Dobra a capacidade da pilha
        pilha = realloc(pilha, capacidade * sizeof(int));  // Realoca memória para o novo tamanho
        pilha[++topo] = elemento;  // Insere o elemento após expandir
    }
}

// Função para remover e retornar o elemento do topo da pilha (pop)
int pop() {
    if (topo == -1) {  // Verifica se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1;  // Retorna -1 para indicar erro
    } else {
        return pilha[topo--];  // Retorna o elemento do topo e decrementa o índice do topo
    }
}

// Função para retornar o elemento do topo sem removê-lo (top)
int top() {
    if (topo == -1) {  // Verifica se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1;  // Retorna -1 para indicar erro
    } else {
        return pilha[topo];  // Retorna o elemento do topo
    }
}

// Função para imprimir todos os elementos da pilha
void imprimir() {
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {  // Percorre a pilha do topo para a base
        printf("%d ", pilha[i]);  // Imprime cada elemento
    }
    printf("\n");
}

// Função para verificar se a pilha está vazia
int estaVazia() {
    return topo == -1;  // Retorna 1 (verdadeiro) se a pilha estiver vazia, 0 (falso) caso contrário
}

int main() {
    pilha = (int*)malloc(INITIAL_SIZE * sizeof(int));  // Aloca memória para a pilha com o tamanho inicial

    push(10);  // Insere 10 na pilha
    push(20);  // Insere 20 na pilha
    push(30);  // Insere 30 na pilha
    imprimir();  // Imprime a pilha

    printf("Elemento no topo: %d\n", top());  // Exibe o elemento no topo
    printf("Elemento removido: %d\n", pop());  // Remove e exibe o elemento do topo
    imprimir();  // Imprime a pilha novamente

    if (estaVazia()) {  // Verifica se a pilha está vazia
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }

    push(40);  // Insere 40 na pilha, provocando a expansão da capacidade
    push(50);  // Insere 50 na pilha
    imprimir();  // Imprime a pilha expandida

    free(pilha);  // Libera a memória alocada para a pilha
    return 0;
}
