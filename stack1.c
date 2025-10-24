#include <stdio.h>

#define N 8

typedef int Data;

typedef struct {
    Data a[N];   // данные
    unsigned int n;  // сколько элементов хранится в стеке
} Stack;

void print(Stack * st)
{
    for (int i = 0; i  < st->n; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}

int main(void)
{
    Stack s = {{7,4,1}, 3};

    Stack * st = &s;

    print(st);

    return 0;
}

