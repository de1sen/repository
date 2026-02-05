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
node_type pop(Node ** ptr_list);
void list_destroy(Node * list);
node_type find_kth_from_end(Node * list, int k);

int main(void)
{
    Node * list = NULL;
    
    // Заполняем список
    push(&list, 7);
    push(&list, 15);
    push(&list, 22);
    push(&list, 52);
    push(&list, 2);
    
    printf("List: ");
    print(list);
    
    int k;
    printf("Enter k (from end): ");
    scanf("%d", &k);
    
    node_type result = find_kth_from_end(list, k);
    
    if (result != -1)  
        printf("%d-th element from end: %d\n", k, result);
    else
        printf("Invalid k or empty list\n");
    
    list_destroy(list);
    
    return 0;
}

node_type find_kth_from_end(Node * list, int k)
{
    if (list == NULL || k <= 0) {
        printf("Error: Empty list or invalid k\n");
        return -1;  
    }
    
    Node * fast = list;
    Node * slow = list;
    
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            printf("Error: k is larger than list size\n");
            return -1;
        }
        fast = fast->next;
    }
    
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow->data;
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

node_type pop(Node ** ptr_list)
{
    if (*ptr_list == NULL) {
        printf("Error: Cannot pop from empty list\n");
        return -1;
    }
    
    Node * ptr = *ptr_list;
    node_type res = ptr->data;
    
    *ptr_list = ptr->next;
    free(ptr);

    return res;
}

void list_destroy(Node * list)
{
    Node * current = list;
    Node * next;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}