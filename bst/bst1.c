#include <stdio.h>

typedef int node_type;

typedef struct Node
{
    node_type data;         // данные в узле
    struct Node * left;     // левый ребёнок
    struct Node * right;    // правый ребёнок
} Node;

Node * tree_add(Node * tree, node_type value);    // добавить значение в дерево
Node * tree_delete(Node * tree, node_type value); // удалить значение из дерева
Node * tree_search(Node * tree, node_type value); // найти значение в дереве
void tree_print(Node * tree);                     // напечатать дерево
void print(Node * tree);

int main(void)
{
    // Модель
    Node 
        seven = {7, NULL, NULL}, 
        nine = {9, NULL, NULL}, 
        two = {2, NULL, NULL}, 
        three = {3, NULL, NULL}, 
        five = {5, NULL, NULL},
        one = {1, NULL, NULL},
        eight = {8, NULL, NULL};

    Node * tree = NULL; // указатель на root
    tree = &seven;
    seven.left = &three;
    seven.right = &nine;
    three.left = &two;
    two.left = &one;
    three.right = &five;
    nine.left = &eight;

    print(tree);

    return 0;
}

void tree_print(Node * tree)
{
    if (tree == NULL)
        return;
    tree_print(tree->left);
    printf("%d ", tree->data);
    tree_print(tree->right);
}

void print(Node * tree)
{
    tree_print(tree);
    printf("\n");
}