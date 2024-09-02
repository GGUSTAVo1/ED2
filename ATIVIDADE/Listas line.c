#include <stdio.h>
#define MAX_SIZE 10  // Define o tamanho máximo da lista como 10

int lista[MAX_SIZE];  // Declara um array estático para armazenar os elementos da lista
int tamanho = 0;  // Variável que mantém o controle do número de elementos na lista

// Função para inserir um elemento na lista
void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {  // Verifica se ainda há espaço na lista
        lista[tamanho++] = elemento;  // Adiciona o elemento e incrementa o tamanho
    } else {
        printf("Lista cheia!\n");  // Exibe mensagem de erro se a lista estiver cheia
    }
}

// Função para remover um elemento da lista pelo índice
void remover(int index) {
    if (index < 0 || index >= tamanho) {  // Verifica se o índice é válido
        printf("Índice inválido!\n");  // Exibe mensagem de erro se o índice for inválido
    } else {
        for (int i = index; i < tamanho - 1; i++) {  // Move os elementos à esquerda para preencher o espaço
            lista[i] = lista[i + 1];
        }
        tamanho--;  // Reduz o tamanho da lista
    }
}

// Função para imprimir todos os elementos da lista
void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {  // Percorre a lista
        printf("%d ", lista[i]);  // Imprime cada elemento
    }
    printf("\n");
}

// Função para buscar a posição de um elemento na lista
int buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) {  // Percorre a lista
        if (lista[i] == elemento) {  // Verifica se o elemento atual é o procurado
            return i;  // Retorna o índice do elemento encontrado
        }
    }
    return -1;  // Retorna -1 se o elemento não for encontrado
}

int main() {
    inserir(10);  // Insere o elemento 10 na lista
    inserir(20);  // Insere o elemento 20 na lista
    inserir(30);  // Insere o elemento 30 na lista
    imprimir();  // Imprime a lista

    int pos = buscar(20);  // Busca o elemento 20 na lista
    if (pos != -1) {
        printf("Elemento 20 encontrado na posição: %d\n", pos);  // Exibe a posição do elemento se encontrado
    } else {
        printf("Elemento 20 não encontrado\n");  // Exibe mensagem se o elemento não for encontrado
    }

    remover(1);  // Remove o elemento na posição 1 (segundo elemento)
    imprimir();  // Imprime a lista após a remoção

    return 0;  // Finaliza o programa
}
