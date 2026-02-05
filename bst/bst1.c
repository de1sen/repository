#include <stdio.h>
#include <stdlib.h>

typedef int node_type;

typedef struct Node
{
    node_type data;         // данные в узле
    struct Node * left;     // левый ребёнок
    struct Node * right;    // правый ребёнок
} Node;

Node * tree_add(Node * tree, node_type value);     // добавить значение в дерево
Node * tree_delete(Node * tree, node_type value);  // удалить значение из дерева
Node * tree_search(Node * tree, node_type value);  // найти значение в дереве
Node * tree_destroy(Node * tree);                  // уничтожить дерево
void tree_print1(Node * tree);                     // напечатать дерево (обход в глубину)
void tree_print2(Node * tree);                     // напечатать дерево (обход в ширину)
void print(Node * tree);
int tree_depth(Node * tree);                       // возвращает глубину дерева


int main(void)
{
    Node * tree = NULL;

    node_type test_data[] = {7, 3, 2, 1, 9, 5, 4, 6};
    for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); i++)
    {
        tree = tree_add(tree, test_data[i]);
        print(tree);
    }
    tree_destroy(tree);

    return 0;
}

void tree_print1(Node * tree)
{
    if (tree == NULL)
        return;
    tree_print1(tree->left);
    printf("%d ", tree->data);
    tree_print1(tree->right);
}

void print(Node * tree)
{
    tree_print1(tree);
    printf("\n");
}

void tree_print2(Node * tree)
{
    if (tree == NULL) 
        return;
    
    Node* queue[100];  
    int front = 0;
    int rear = 0;
    
    queue[rear++] = tree;
    
    
    while (front < rear) 
    {
        Node* current = queue[front++];
        
        printf("%d ", current->data);
        
        if (current->left != NULL) 
        {
            queue[rear++] = current->left;
        }
        
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

Node * tree_add(Node * tree, node_type value)
{
    if (tree == NULL)
    {
        Node * t = malloc(sizeof(Node));
        t->data = value;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    
    if (value < tree->data)
    {
        tree->left = tree_add(tree->left, value);
    }

    if (value > tree->data)
    {
        tree->right = tree_add(tree->right, value);
    }
    
    return tree;
}

Node * tree_destroy(Node * tree)
{
    if (tree == NULL)
        return NULL;

    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free(tree);
    return NULL;
}

int tree_depth(Node * tree)
{
    if (tree == NULL)
        return 0;

    int left_height = tree_depth(tree->left);
    int right_height = tree_depth(tree->right);

    if (left_height > right_height)
        return left_height + 1;
    else
        return right_height + 1;
}
