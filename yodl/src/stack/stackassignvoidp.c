#include "stack.ih"

/*
    stack will own `value': its destructor will eventually be called by the
stack. stack_assign will push value on the stack if it's still empty.
*/

void stack_assignVoidP(register Stack *sp, register void *value)
{
    size_t n = sp->d_n;

    if (!n)
        stack_pushVoidP(sp, value);
    else
    {
        (*sp->d_destructor)(sp->d_value[n - 1].u_voidP);
        sp->d_value[n - 1].u_voidP = value;
    }
}
