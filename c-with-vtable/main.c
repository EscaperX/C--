#include <stdio.h>
// #include "stack_interface.h"
#include "stack_array.h"

int main()
{
    struct Stack *stack = stack_array_create();
    stack_pop(stack);
    stack_top(stack);
    return 0;
}