#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define N 10            // на сколько будет изменяться размер стека в штуках

typedef int Data;

typedef struct {
    Data * a;           // данные
    unsigned int n;  // сколько элементов хранится в стеке
    size_t size;        // для скольки элементов выделена память
} Stack;    

void print(Stack * st);
void init(Stack * st);
void push(Stack * st, Data d);
Data pop(Stack * st);
int is_empty(Stack * st);
int is_full(Stack * st);
void destroy(Stack * st);

int main()
{
    Stack stack;        // создаем стек
    Stack * st = &stack;// указатель на созданный стек

    init(st);
    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO
    print(st);          // ничего не печатается 

    Data test[] = {5, 17, -3, 0, 1, 2, 3, 4};

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

    destroy(st);

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
    st->size = 0;
    st->a = NULL;    
}

void push(Stack * st, Data d)
{
    if (is_full(st)) {
        st->size += N;
        st->a = realloc(st->a, st->size * sizeof(Data));    
    }
    st->a[st->n] = d;
    st->n ++;
}

Data pop(Stack * st)
{
    if (!is_empty(st)) {   
        Data res = st->a[st->n - 1];
        st->n --;
        return res;
    }
    return 0; 
}

int is_empty(Stack *st)
{
    return st->n == 0;
}

int is_full(Stack *st)
{
    return st->n == st->size;
}

void destroy(Stack * st)
{
    free(st->a);
    st->n = 0;
    st->size = 0;
    st->a = NULL;
}
