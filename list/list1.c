#include <stdio.h>

typedef int node_type;
typedef struct Node Node;
struct Node 
{
    node_type data;
    Node * next;
};

void print(Node * list);

int main(void)
{
    Node * list = NULL;
    Node a = {3}, b = {7}, c = {13};
    list = &a;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    print(list);

    return 0;
}

void print(Node * list)
{
    for (Node * ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->data);
    printf("\n");
}
