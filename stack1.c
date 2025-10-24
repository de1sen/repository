#include <stdio.h>

#define N 8

typedef int Data;

typedef struct {
    Data a[N];   // данные
    unsigned int size;  // сколько элементов хранится в стеке
} Stack;

void print(Stack * st);
void init(Stack * st);
void push(Stack * st, Data d);
Data pop(Stack * st);
int is_empty(Stack * st);

int main(void)
{
    Stack s;

    Stack * st = &s;

    init(st);
    printf("empty : %s\n", is_empty(st) ? "YES" : "NO"); // YES

    push(st,7);
    push(st,7);
    push(st,7);
    printf("empty : %s\n", is_empty(st) ? "YES" : "NO");  // NO

    print(st); // 7 7 7

    pop(st); 
    print(st); // 7 7
 
    return 0;
}

void print(Stack * st)
{
    for (unsigned int i = 0; i  < st->size; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}

void init(Stack * st)
{
    st->size = 0;
}

void push(Stack * st, Data d)
{
    st->a[st->size] = d;
    st->size ++;
}

Data pop(Stack * st)
{
    Data res = st->a[st->size - 1];
    st->size --;
    return res;
}

int is_empty(Stack *st)
{
    return st->size == 0;
}


