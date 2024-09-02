#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da fila
typedef struct Node {
    int data;  // Dado armazenado no nó
    struct Node* next;  // Ponteiro para o próximo nó
} Node;

// Estrutura da fila, que mantém ponteiros para o início (front) e o fim (rear) da fila
typedef struct Queue {
    Node* front;  // Ponteiro para o primeiro nó da fila
    Node* rear;   // Ponteiro para o último nó da fila
} Queue;

// Função para criar uma fila vazia
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));  // Aloca memória para a fila
    if (q == NULL) {  // Verifica se a alocação foi bem-sucedida
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;  // Inicializa a fila vazia
    return q;  // Retorna o ponteiro para a fila
}

// Função para adicionar um elemento à fila (enqueue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Aloca memória para o novo nó
    if (newNode == NULL) {  // Verifica se a alocação foi bem-sucedida
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;  // Armazena o valor no nó
    newNode->next = NULL;  // O novo nó será o último, então seu próximo é NULL
    if (q->rear == NULL) {  // Se a fila estiver vazia
        q->front = q->rear = newNode;  // Ambos front e rear apontam para o novo nó
    } else {  // Se a fila não estiver vazia
        q->rear->next = newNode;  // O nó atual em rear aponta para o novo nó
        q->rear = newNode;  // O novo nó se torna o último da fila
    }
}

// Função para remover um elemento da fila (dequeue)
int dequeue(Queue* q) {
    if (q->front == NULL) {  // Verifica se a fila está vazia
        printf("Fila está vazia.\n");
        return -1;  // Retorna -1 para indicar erro
    }
    Node* temp = q->front;  // Armazena o nó que será removido
    int data = temp->data;  // Armazena o dado do nó que será removido
    q->front = q->front->next;  // Avança o ponteiro front para o próximo nó
    if (q->front == NULL) {  // Se a fila ficou vazia após o dequeue
        q->rear = NULL;  // Rear também deve ser NULL
    }
    free(temp);  // Libera a memória do nó removido
    return data;  // Retorna o dado removido
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;  // Retorna 1 se a fila estiver vazia, 0 caso contrário
}

// Função para imprimir todos os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {  // Verifica se a fila está vazia
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;  // Começa no primeiro nó da fila
    printf("Elementos da fila: ");
    while (temp != NULL) {  // Percorre todos os nós da fila
        printf("%d ", temp->data);  // Imprime o dado do nó
        temp = temp->next;  // Avança para o próximo nó
    }
    printf("\n");
}

// Função para contar o número de elementos na fila
int contarElementos(Queue* q) {
    int count = 0;
    Node* temp = q->front;
    while (temp != NULL) {  // Percorre todos os nós da fila
        count++;  // Incrementa o contador para cada nó
        temp = temp->next;  // Avança para o próximo nó
    }
    return count;  // Retorna o número de elementos na fila
}

// Função para limpar todos os elementos da fila, liberando a memória
void limparFila(Queue* q) {
    while (!isEmpty(q)) {  // Enquanto a fila não estiver vazia
        dequeue(q);  // Remove cada elemento
    }
    printf("Todos os elementos foram removidos e a fila está limpa.\n");
}

int main() {
    Queue* q = createQueue();  // Cria uma nova fila
    enqueue(q, 10);  // Adiciona 10 à fila
    enqueue(q, 20);  // Adiciona 20 à fila
    enqueue(q, 30);  // Adiciona 30 à fila
    printQueue(q);  // Imprime a fila

    printf("Desenfileirado: %d\n", dequeue(q));  // Remove e imprime o primeiro elemento da fila
    printQueue(q);  // Imprime a fila novamente
    printf("Desenfileirado: %d\n", dequeue(q));  // Remove e imprime o próximo elemento
    printQueue(q);  // Imprime a fila novamente
    printf("Desenfileirado: %d\n", dequeue(q));  // Remove e imprime o último elemento
    printQueue(q);  // Imprime a fila, agora vazia

    enqueue(q, 40);  // Adiciona 40 à fila
    enqueue(q, 50);  // Adiciona 50 à fila
    printQueue(q);  // Imprime a fila novamente

    printf("Número de elementos na fila: %d\n", contarElementos(q));  // Conta e imprime o número de elementos na fila

    limparFila(q);  // Limpa todos os elementos da fila
    printQueue(q);  // Verifica e imprime a fila após a limpeza

    free(q);  // Libera a memória alocada para a estrutura da fila
    return 0;
}
