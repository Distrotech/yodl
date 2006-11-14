#include "counter.ih"

void counter_add(HashItem *item, int value)
{
    Stack *sp = co_sp(item, true);

    if (sp != PFAILED)
        stack_assignInt(sp, stack_tos(sp).u_int + value);
}
