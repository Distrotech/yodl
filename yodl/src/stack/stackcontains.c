#include "stack.ih"

bool stack_contains(Stack *sp, void const *value)
{
    register StackUnion *vp = sp->d_value;
    register size_t idx;

    for (idx = sp->d_n; idx--; vp++)
    {
        if (value == vp->u_voidP)
            return true;
    }

    return false;
}
