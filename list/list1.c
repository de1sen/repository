#include <stdio.h>
#include <stdlib.h>

typedef int node_type;
typedef struct Node Node;
struct Node 
{
    node_type data;
    Node * next;
};

void print(Node * list);
void push(Node ** ptr_list, node_type value);
int is_empty(Node * list);

int main(void)
{
    node_type test[] = {3, 7, 13, 10};
    Node * list = NULL;
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

    for (size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++)
    {
        push(&list, test[i]);
        print(list);
    }

    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

    return 0;
}

void print(Node * list)
{
    for (Node * ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->data);
    printf("\n");
}

void push(Node ** ptr_list, node_type value)
{
    Node * ptr = malloc(sizeof(Node));
    ptr->data = value;
    ptr->next = *ptr_list;
    *ptr_list = ptr;
}

int is_empty(Node * list)
{
    return list == NULL;
}