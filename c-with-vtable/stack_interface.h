#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

struct Stack
{
    const struct StackInterface *const vtable;
};

struct StackInterface
{
    int (*top)(struct Stack *);
    int (*pop)(struct Stack *);
};

int stack_top(struct Stack *);
int stack_pop(struct Stack *);

#endif