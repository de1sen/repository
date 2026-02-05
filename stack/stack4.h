#ifndef STACK_H
#define STACK_H

#include <sys/types.h> 

#ifndef STACK_TYPE
#define STACK_TYPE int
#endif

typedef STACK_TYPE stack_type;

enum types_of_errors 
{
    NO_ERRORS = 0b00000,
    WRONG_MAIN_POINTER = 0b10000,
    WRONG_STACK_POINTER = 0b01000,
    WRONG_SIZE = 0b00100,
    WRONG_CAPACITY = 0b00010,
    MEMORY_ERROR = 0b00001
};

enum status 
{
    SUCCESS = 1,
    FAILURE = 0
};

typedef struct 
{
    stack_type* data;
    ssize_t size;
    ssize_t capacity;
} Stack;

enum status stack_ctor(Stack* stack, int initial_capacity);
enum status stack_push(Stack* stack, stack_type value);
enum status stack_pop (Stack* stack, stack_type* pop_value);
void stack_dtor(Stack* stack);
unsigned int stack_verif(Stack* stack);
stack_type hash_djb2 (Stack* stack);
void stack_dump(Stack* stack, unsigned int error_code);
void stack_printf(unsigned int index, stack_type value);

extern bool IS_WAS_DUMP;
extern const ssize_t VERY_BIG_NUMBER;
extern unsigned int CODE;
extern const stack_type CANAREIKA;
extern stack_type global_valid_hash;    

#define VERIFY      if(!IS_WAS_DUMP)                       \
                    {                                      \
                        if((CODE = stack_verif(stack)) != 0) \
                        {                                  \
                            stack_dump(stack, CODE);         \
                            IS_WAS_DUMP = true;            \
                            return FAILURE;                \
                        }                                  \
                    }

#ifdef DEBUG
#define ON_DEBUG(code) code
#define ON_DEBUG_ELSE(code)
#else 
#define ON_DEBUG(code)
#define ON_DEBUG_ELSE(code) code
#endif //DEBUG


#endif