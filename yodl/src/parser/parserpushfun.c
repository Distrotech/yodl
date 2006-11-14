#include "parser.ih"

void parser_push_fun(char const *fun)
{
    stack_pushVoidP(&ps_fun_st, (void *)fun);   /* fun not modified */
}
