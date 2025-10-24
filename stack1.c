#include <stdio.h>

#define N 8

typedef int Data;

typedef struct {
    Data a[N];   // данные
    unsigned int n;  // сколько элементов хранится в стеке
} Stack;

int main(void)
{
    Stack s = {{7,4,1}, 3};

    Stack * st = &s;

    return 0;
}