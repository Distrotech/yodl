#include "macro.ih"

Result macro_push(Macro *macro, char const *definition, size_t nargs)
{
    stack_pushVoidP(&macro->d_definition, new_str(definition));
    stack_pushInt(&macro->d_arg, nargs);

    return SUCCESS;
}
