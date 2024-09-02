#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista duplamente encadeada
typedef struct Node {
    int data;  // Armazena o valor do nó
    struct Node* next;  // Ponteiro para o próximo nó na lista
    struct Node* prev;  // Ponteiro para o nó anterior na lista
} Node;

Node* head = NULL;  // Ponteiro para o primeiro nó da lista

// Função para inserir um valor no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Aloca memória para o novo nó
    newNode->data = value;  // Atribui o valor ao novo nó
    newNode->next = head;  // O próximo nó será o atual 'head'
    newNode->prev = NULL;  // Como é o primeiro nó, não tem nó anterior
    if (head != NULL)  // Se a lista não estiver vazia
        head->prev = newNode;  // Atualiza o ponteiro 'prev' do nó que era o primeiro
    head = newNode;  // Atualiza o ponteiro 'head' para o novo nó
}

// Função para deletar um nó da lista
void deleteNode(Node* node) {
    if (node == head)  // Se o nó a ser deletado for o primeiro nó
        head = node->next;  // Atualiza o 'head' para o próximo nó
    if (node->next != NULL)  // Se o nó não for o último
        node->next->prev = node->prev;  // O próximo nó aponta para o nó anterior
    if (node->prev != NULL)  // Se o nó não for o primeiro
        node->prev->next = node->next;  // O nó anterior aponta para o próximo nó
    free(node);  // Libera a memória alocada para o nó
}

// Função para imprimir todos os valores da lista
void printList() {
    Node* temp = head;  // Começa pelo primeiro nó
    while (temp != NULL) {  // Percorre até o final da lista
        printf("%d ", temp->data);  // Imprime o valor do nó atual
        temp = temp->next;  // Move para o próximo nó
    }
    printf("\n");
}

// Função para buscar um valor específico na lista
void searchAndPrintNeighbors(int value) {
    Node* temp = head;  // Começa pelo primeiro nó
    while (temp != NULL) {  // Percorre até o final da lista
        if (temp->data == value) {  // Se encontrar o valor
            printf("Valor %d encontrado.\n", value);
            if (temp->prev != NULL)  // Se o nó anterior existir
                printf("Valor anterior: %d\n", temp->prev->data);
            else
                printf("Não há valor anterior (este é o primeiro nó).\n");
            if (temp->next != NULL)  // Se o próximo nó existir
                printf("Próximo valor: %d\n", temp->next->data);
            else
                printf("Não há próximo valor (este é o último nó).\n");
            return;
        }
        temp = temp->next;  // Move para o próximo nó
    }
    printf("Valor %d não encontrado na lista.\n", value);  // Se não encontrar o valor
}

int main() {
    int escolha, valor;

    do {
        printf("\n1. Inserir um valor\n");
        printf("2. Imprimir lista\n");
        printf("3. Buscar um valor\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite um valor para inserir na lista: ");
                scanf("%d", &valor);
                insertFront(valor);  // Insere o valor informado pelo usuário
                break;
            case 2:
                printList();  // Imprime a lista
                break;
            case 3:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                searchAndPrintNeighbors(valor);  // Busca o valor e exibe os vizinhos se encontrado
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}
