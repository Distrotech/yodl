#include "macro.ih"

size_t macro_nArgs(Macro const *macro)
{
    return (size_t)stack_tos(&macro->d_arg);
}
