#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct PatriciaNode {
    char *word; // Palavra armazenada no nó (NULL se for intermediário)
    struct PatriciaNode *left, *right; // Filhos
} PatriciaNode;

// Função para criar um novo nó
PatriciaNode* createNode(const char *word) {
    PatriciaNode *newNode = (PatriciaNode*)malloc(sizeof(PatriciaNode));
    newNode->word = word ? strdup(word) : NULL;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inserir palavra na Árvore Patricia
void insertWord(PatriciaNode **root, const char *word) {
    if (*root == NULL) {
        *root = createNode(word);
        return;
    }
    PatriciaNode *current = *root;
    while (1) {
        if (strcmp(word, current->word) < 0) {
            if (current->left == NULL) {
                current->left = createNode(word);
                return;
            }
            current = current->left;
        } else if (strcmp(word, current->word) > 0) {
            if (current->right == NULL) {
                current->right = createNode(word);
                return;
            }
            current = current->right;
        } else {
            return; // Palavra já existe
        }
    }
}

// Buscar palavra na Árvore Patricia
int searchWord(PatriciaNode *root, const char *word) {
    while (root != NULL) {
        if (strcmp(word, root->word) == 0)
            return 1;
        root = strcmp(word, root->word) < 0 ? root->left : root->right;
    }
    return 0;
}

// Sugerir palavras baseadas em prefixo
void suggestWords(PatriciaNode *root, const char *prefix, int depth) {
    if (root == NULL) return;

    if (root->word && strncmp(root->word, prefix, strlen(prefix)) == 0) {
        printf("%s\n", root->word);
    }

    suggestWords(root->left, prefix, depth + 1);
    suggestWords(root->right, prefix, depth + 1);
}

// Carregar palavras do arquivo dicionario.txt
void loadDictionary(PatriciaNode **root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        insertWord(root, word);
    }
    fclose(file);
}

// Menu interativo
void menu(PatriciaNode *root) {
    int choice;
    char input[MAX_WORD_LEN];
    do {
        printf("\nMenu:\n");
        printf("1. Inserir palavra\n");
        printf("2. Buscar palavra\n");
        printf("3. Sugerir palavras\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        getchar(); // Limpa o buffer de entrada

        switch (choice) {
            case 1:
                printf("Digite a palavra para inserir: ");
                scanf("%s", input);
                insertWord(&root, input);
                printf("Palavra '%s' inserida com sucesso!\n", input);
                break;
            case 2:
                printf("Digite a palavra para buscar: ");
                scanf("%s", input);
                if (searchWord(root, input)) {
                    printf("Palavra '%s' encontrada no dicionário.\n", input);
                } else {
                    printf("Palavra '%s' não encontrada no dicionário.\n", input);
                }
                break;
            case 3:
                printf("Digite o prefixo para sugestão: ");
                scanf("%s", input);
                printf("Sugestões:\n");
                suggestWords(root, input, 0);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (choice != 4);
}

int main() {
    PatriciaNode *dictionary = NULL;

    // Carregar o dicionário do arquivo
    printf("Carregando dicionário...\n");
    loadDictionary(&dictionary, "dicionario.txt");
    printf("Dicionário carregado com sucesso!\n");

    // Iniciar o menu
    menu(dictionary);

    return 0;
}
