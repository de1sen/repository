#include <stdio.h>

#define N 8

typedef int Data;

typedef struct {
    Data a[N];   // данные
    unsigned int n;  // сколько элементов хранится в стеке
} Stack;

void print(Stack * st);
void init(Stack * st);
void push(Stack * st, Data d);

int main(void)
{
    Stack s;

    Stack * st = &s;

    init(st);
    print(st);

    return 0;
}

void print(Stack * st)
{
    for (unsigned int i = 0; i  < st->n; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}

void init(Stack * st)
{
    st->n = 0;
}

void push(Stack * st, Data d)
{
    st->a[st->n] = d;
    st->n ++;
}
