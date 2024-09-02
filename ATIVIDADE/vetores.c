#include <stdio.h>

#define MAX 10  // Define um tamanho máximo para o vetor

// Função para inverter o vetor
void inverterVetor(int vetor[], int n) {
    int i, temp;
    for (i = 0; i < n / 2; i++) {
        temp = vetor[i];  // Guarda o valor do elemento atual em 'temp'
        vetor[i] = vetor[n - 1 - i];  // Atribui o valor do elemento simétrico ao atual
        vetor[n - 1 - i] = temp;  // Atribui o valor guardado em 'temp' ao elemento simétrico
    }
}

int main() {
    int n, i;

    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor (até %d): ", MAX);
    scanf("%d", &n);

    // Verifica se o tamanho do vetor não excede o limite
    if (n > MAX) {
        printf("Tamanho do vetor excede o limite de %d.\n", MAX);
        return 1;
    }

    int vetor[MAX];  // Declaração do vetor com tamanho máximo fixo

    // Solicita ao usuário para preencher o vetor
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Chama a função para inverter o vetor
    inverterVetor(vetor, n);

    // Impressão do vetor invertido
    printf("Vetor invertido:\n");
    for (i = 0; i < n; i++) {  // Percorre todos os elementos do vetor
        printf("%d ", vetor[i]);  // Imprime o valor de cada elemento
    }

    return 0;
}
