#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h> 

#include "stack4.h"

bool IS_WAS_DUMP              = false;
const ssize_t VERY_BIG_NUMBER = 1000000000;
unsigned int CODE             = 0b00000;
const stack_type CANAREIKA    = 0xEDA;
stack_type global_valid_hash  = 5381;

enum status stack_ctor(Stack* stack, int initial_capacity)
{
    int canary_size = 0;

    ON_DEBUG (canary_size = 2;)     

    stack->data = (stack_type*)calloc(initial_capacity + canary_size, sizeof(stack_type));

    ON_DEBUG (stack->data[0] = stack->data[initial_capacity + 1] == CANAREIKA);

    stack->size = 0;
    stack->capacity = initial_capacity;

    VERIFY 

    return SUCCESS;
}

enum status stack_push(Stack* stack, stack_type value)
{
    VERIFY 

    if (stack->size == stack->capacity) 
    {
        ON_DEBUG (ssize_t old_capacity = stack->capacity;)
        stack->capacity = (stack->capacity == 0) ? 1 : stack->capacity * 2;

        stack_type* new_data = (stack_type*)realloc(stack->data, (stack->capacity ON_DEBUG( + 2 )) * sizeof(stack_type));

        if (new_data == NULL)
        {
            return FAILURE;
        }

        stack->data = new_data;

        ON_DEBUG (for (ssize_t i = old_capacity + 1; i <= stack->capacity; i++)
                    {
                        stack->data[i] = 0;
                    })

        ON_DEBUG (stack->data[stack->capacity + 1] == CANAREIKA;)
    }

    stack->data[stack->size ON_DEBUG( + 1 )] = value;
    stack->size++;
    global_valid_hash = global_valid_hash * 33 + value;

    VERIFY

    return SUCCESS;
}

enum status stack_pop(Stack* stack, stack_type* pop_value)
{
    VERIFY

    if (stack->size == 0)
    {
        printf("Error: stack is empty!\n");
        return FAILURE;
    }

    stack->size--;
    *pop_value = stack->data[stack->size ON_DEBUG( + 1 )];
    stack->data[stack->size ON_DEBUG( + 1 )] = 0;
    global_valid_hash = (global_valid_hash - *pop_value) / 33;

    VERIFY 

    return SUCCESS;
}

stack_type hash_djb2(Stack* stack)
{
    stack_type hash = 5381; 

    for (int i = 0;i < stack->size; i++)
    {
        hash = hash * 33 + stack->data[i];
    } 
    
    return hash;
}

void stack_dtor(Stack* stack)
{
    free(stack->data);
    stack->data = NULL;

    stack->size = -1;
    stack->capacity = -1;
}

unsigned int stack_verif(Stack* stack)
{
    unsigned int error_code = 0b00000;

    if (stack == NULL)
        error_code |= 0b10000;

    else if (stack->data == NULL)
        error_code |= 0b01000;

    else if (stack->size < 0 || stack->size == stack->capacity + 1 || stack->size > VERY_BIG_NUMBER)
        error_code |= 0b00100;

    else if (stack->capacity <= 0 || stack->capacity > VERY_BIG_NUMBER)
        error_code |= 0b00010;
    
    ON_DEBUG (
        else if (stack->data[0] != CANAREIKA || stack->data[stack->capacity + 1] != CANAREIKA || global_valid_hash != hash_djb2(stack))
        error_code |= 0b00001;
    )

    return error_code;
}

void stack_dump(Stack* stack, unsigned int error_code)
{
    printf("stack_dump()");

    printf("\nstack: [%p]", stack);

    if (error_code & WRONG_MAIN_POINTER)
    {
        printf("WRONG POINTER");
        return;
    }

    printf("\n{\n");

    printf("size     = %ld ", stack->size);
    if (error_code & WRONG_SIZE)
        printf("WRONG SIZE");

    printf("\ncapacity = %ld ", stack->capacity);
    if (error_code & WRONG_CAPACITY)
        printf("WRONG CAPACITY");

    printf("\ndata [%p] ", stack->data);
    if (error_code & WRONG_STACK_POINTER)
    {
        printf("WRONG STACK POINTER\n");
        return;
    }

    printf("\n");

    ON_DEBUG (
    if (error_code & MEMORY_ERROR)
        printf("MEMORY_ERROR\n");
    )

    for (ssize_t i = 0; i < stack->capacity ON_DEBUG(+ 2); i++)
    {
        ON_DEBUG (
        if(i < stack->size + 1 && i != 0 && i != stack->capacity + 1)
            printf("*");
        )

        ON_DEBUG_ELSE (
        if(i < stack->size)
            printf("*");
        )

        stack_printf(i, stack->data[i]);
    }

    printf("\n}\n");
}

void stack_printf(unsigned int index, stack_type value)
{
    printf("index: %d\nvalue: %d\n", index, value);
}

int main(void)
{
    Stack stack;  
    
    stack_ctor(&stack, 10);  

    for (int i = 0; i < 10; i++)
    {
        stack_push(&stack, i * 2);
    }

    printf("%u\n", stack_verif(&stack));
    
    stack_dtor(&stack); 

    return 0;
}