#include "stack.ih"

void stack_destroy(void *sp)
{
    size_t idx = ((Stack *)sp)->d_n;
    register StackUnion *stack = ((Stack *)sp)->d_value;

    for ( ; idx--; stack++)
        (*((Stack *)sp)->d_destructor)(stack->u_voidP);

    free(((Stack *)sp)->d_value);
}
