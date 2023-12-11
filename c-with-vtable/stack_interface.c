#include "stack_interface.h"

int stack_top(struct Stack *s) { return s->vtable->top(s); }
int stack_pop(struct Stack *s) { return s->vtable->pop(s); }