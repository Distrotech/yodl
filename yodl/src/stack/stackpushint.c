#include "stack.ih"

Result stack_pushInt(register Stack *sp, register int element)
{
    register size_t last = sp->d_n++;

    if (last == sp->d_size)
        new_size(&sp->d_value, sp->d_size += STACK_BLOCK,
                                            last, sizeof(StackUnion));

    sp->d_value[last].u_int = element;

    return SUCCESS;
}
