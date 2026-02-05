#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;

typedef struct Node {
    Data value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;  
    Node* tail;   
    size_t size;     
} Queue;

Queue* queue_create();
void queue_enqueue(Queue* queue, Data value);
Data queue_dequeue(Queue* queue);
Data queue_front(Queue* queue);
bool queue_is_empty(Queue* queue);
int queue_size(Queue* queue);
void queue_print(Queue* queue);
void queue_clear(Queue* queue);
void queue_destroy(Queue* queue);

int main() 
{
    Queue* queue = queue_create();
    
    printf("Is queue empty? %s\n", queue_is_empty(queue) ? "Yes" : "No");
    
    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);
    queue_enqueue(queue, 30);
    queue_enqueue(queue, 40);
    
    printf("Queue size: %d\n", queue_size(queue));
    queue_print(queue);
    
    printf("Front element: %d\n", queue_front(queue));
    
    printf("Dequeued: %d\n", queue_dequeue(queue));
    printf("Dequeued: %d\n", queue_dequeue(queue));
    
    queue_print(queue);

    queue_enqueue(queue, 50);
    queue_enqueue(queue, 60);
    
    queue_print(queue);
    
    printf("Queue size: %d\n", queue_size(queue));

    printf("\nClearing queue...\n");
    while (!queue_is_empty(queue)) 
    {
        printf("Dequeued: %d\n", queue_dequeue(queue));
    }
    
    printf("Is queue empty? %s\n", queue_is_empty(queue) ? "Yes" : "No");
    
    queue_destroy(queue);
    
    return 0;
}

Queue* queue_create() 
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) 
    {
        printf("Memory allocation failed for queue\n");
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void queue_enqueue(Queue* queue, Data value) 
{
    if (queue == NULL) 
    {
        printf("Queue is NULL\n");
        return;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        printf("Memory allocation failed for new node\n");
        return;
    }
    
    new_node->value = value;
    new_node->next = NULL;
    
    if (queue->tail == NULL) 
    {
        queue->head = new_node;
        queue->tail = new_node;
    } 
    else 
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    
    queue->size++;
}

Data queue_dequeue(Queue* queue) 
{
    if (queue == NULL || queue_is_empty(queue)) 
    {
        printf("Queue is empty or NULL\n");
        return 0;
    }
    
    Node* temp = queue->head;
    Data value = temp->value;
    
    queue->head = queue->head->next;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(temp);
    queue->size--;
    
    return value;
}

Data queue_front(Queue* queue) 
{
    if (queue == NULL || queue_is_empty(queue)) 
    {
        printf("Queue is empty or NULL\n");
        return 0;
    }
    return queue->head->value;
}

bool queue_is_empty(Queue* queue) 
{
    return (queue == NULL || queue->head == NULL);
}

int queue_size(Queue* queue) 
{
    if (queue == NULL) 
        return 0;
    return queue->size;
}

void queue_print(Queue* queue) 
{
    if (queue == NULL || queue_is_empty(queue)) 
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue (head -> tail): ");
    Node* current = queue->head;
    while (current != NULL) 
    {
        printf("%d", current->value);
        if (current->next != NULL) 
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void queue_clear(Queue* queue) 
{
    if (queue == NULL) return;
    
    while (!queue_is_empty(queue)) 
    {
        queue_dequeue(queue);
    }
}

void queue_destroy(Queue* queue) 
{
    if (queue == NULL) 
    return;
    
    queue_clear(queue);
    
    free(queue);
}