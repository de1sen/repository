// стек в 1 malloc 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define N 10            // на сколько будет изменяться размер стека в штуках

typedef int Data;

typedef struct {           
    unsigned int n;     // сколько элементов хранится в стеке
    size_t size;        // ёмкость стека(для скольки элементов выделена память)
    Data a[1];          // данные    
} Stack;    

void print(Stack *st);
void init(Stack *st);
void push(Stack **pst, Data d);
Data pop(Stack *st);
int is_empty(Stack *st);
int is_full(Stack *st);
void clear(Stack *st);
Stack * destroy(Stack *st);
Stack * create();

int main(void)
{
    Data test[N] = {5, 17, -3, 0, 1, 2, 3, 4,8,13};
    Stack * st = create();      // создаём стек

    printf("empty: %s\n", is_empty(st) ? "YES" : "NO"); // YES
    printf("full: %s\n", is_full(st) ? "YES" : "NO");   // NO
    print(st);          // ничего не печатается 

    Data d;
    // тесты для push
    for(int i = 0; i < N; i++) {
        d = test[i];
        printf("push %d :", d);
        push(&st, d);
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

void print(Stack *st)
{
    for (unsigned int i = 0; i  < st->n; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}

void push(Stack **pst, Data data)
{
    if (is_full(*pst)) {
        (*pst)->size += N;
        *pst  = realloc(*pst, sizeof(Stack) + (*pst)->size * sizeof(Data));    
    }
    Stack * st = *pst;
    st->a[st->n] = data;
    st->n ++;
}

Data pop(Stack *st)
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

Stack * create()
{
    Stack * st = malloc(sizeof(Stack) + sizeof(Data) * N);
    st->size = N;
    st->n = 0;
    return st;
}

Stack * destroy(Stack * st)
{
    if (st != NULL) {
        free(st);
    }
    return NULL;
}