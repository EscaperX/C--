#include "stack_array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StackArray
{
    struct Stack base;
    int idx;
    int array[100];
};

static int stack_array_top(struct Stack *s)
{
    puts(__PRETTY_FUNCTION__);
}

static int stack_array_pop(struct Stack *s)
{
    puts(__PRETTY_FUNCTION__);
}

struct Stack *stack_array_create()
{
    static const struct StackInterface vtable = {
        stack_array_top, stack_array_pop};
    static struct Stack base = {&vtable};
    struct StackArray *sa = (struct StackArray *)malloc(sizeof(struct StackArray));
    memcpy(&sa->base, &base, sizeof(struct Stack));
    sa->idx = 0;
    return &sa->base;
}