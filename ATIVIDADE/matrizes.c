#include <stdio.h>
#include <stdlib.h>  // Necessário para malloc

int main() {
    int n, i, j, soma = 0;

    // Solicita ao usuário o tamanho da matriz (n x n)
    printf("Digite o tamanho da matriz (n x n): ");
    scanf("%d", &n);

    // Aloca dinamicamente a memória para uma matriz de tamanho n x n
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Verifica se a alocação de memória foi bem-sucedida
    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Solicita ao usuário que insira os elementos da matriz
    printf("Insira os elementos da matriz %dx%d:\n", n, n);
    for (i = 0; i < n; i++) {  // Percorre as linhas da matriz
        for (j = 0; j < n; j++) {  // Percorre as colunas da matriz
            scanf("%d", &matriz[i][j]);  // Lê o elemento e armazena na matriz
            if (i == j) {  // Verifica se o elemento está na diagonal principal
                soma += matriz[i][j];  // Soma os elementos da diagonal principal
            }
        }
    }

    // Imprime a soma dos elementos da diagonal principal
    printf("Soma dos elementos da diagonal principal: %d\n", soma);

    return 0;
}
