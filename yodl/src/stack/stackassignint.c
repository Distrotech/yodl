#include "stack.ih"

/*
    stack will own `value': its destructor will eventually be called by the
stack. stack_assign will push value on the stack if it's still empty.
*/

void stack_assignInt(register Stack *sp, register int value)
{
    size_t n = sp->d_n;

    if (!n)
        stack_pushInt(sp, value);
    else
    {
        (*sp->d_destructor)(sp->d_value[n - 1].u_voidP);
        sp->d_value[n - 1].u_int = value;
    }
}
