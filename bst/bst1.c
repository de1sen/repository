#include <stdio.h>

typedef int node_type;

typedef struct 
{
    node_type data;         // данные в узле
    struct Node * left;     // левый ребёнок
    struct Node * right;    // правый ребёнок
} Node;

Node * tree_add(Node * tree, node_type value);    // добавить значение в дерево
Node * tree_delete(Node * tree, node_type value); // удалить значение из дерева
Node * tree_search(Node * tree, node_type value); // найти значение в дереве
void tree_print(Node * tree);                     // напечатать дерево

int main(void)
{
    // Модель
    Node 
        seven = {7, NULL, NULL}, 
        nine = {9, NULL, NULL}, 
        two = {2, NULL, NULL}, 
        three = {3, NULL, NULL}, 
        five = {5, NULL, NULL};

    Node * tree = NULL; // указатель на root

    return 0;
}