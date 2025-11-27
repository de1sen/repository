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

int main(void)
{
    Node * list = NULL;
    Node a = {3}, b = {7}, c = {13};
    list = &a;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    print(list);

    push(&list, 10);

    print(list);
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