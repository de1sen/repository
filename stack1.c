#include <stdio.h>
#include <assert.h>

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
int is_full(Stack * st);

int main()
{
    Stack stack;            // создаем стек
    Stack * st = &stack;    // указатель на созданный стек

    init(st);
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO
    print(st);              // ничего не печатается

    Data test[] = {5, 17, -3, 0, 1, 2, 3, 4};
    // проверили, что чисел столько, сколько размер стека
    assert(sizeof(test) == sizeof(st->a));

    Data d;
    // тесты для push
    for(int i = 0; i < N; i++) {
        d = test[i];
        printf("push %d :", d);
        push(st, d);
        print(st);
        printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // NO
    }

    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // YES

    // тесты для pop
    for(int i = 0; i < N; i++) {
        d = pop(st);
        printf("pop %d :", d);
        print(st);      // pop -3: 5 17
    }
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO

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
    if (!is_full(st)) {
        st->a[st->size] = d;
        st->size ++;
    }
}

Data pop(Stack * st)
{
    if (!is_empty(st)) {   
        Data res = st->a[st->size - 1];
        st->size --;
        return res;
    }
    return 0;
}

int is_empty(Stack *st)
{
    return st->size == 0;
}

int is_full(Stack *st)
{
    return st->size == sizeof(st->a)/sizeof(st->a[0]);
}

