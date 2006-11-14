#include "stack.ih"

bool stack_contains(Stack *sp, void const *value)
{
    register void **vp = sp->d_value;
    register size_t idx;

    for (idx = sp->d_n; idx--; vp++)
    {
        if (value == *vp)
            return true;
    }

    return false;
}
