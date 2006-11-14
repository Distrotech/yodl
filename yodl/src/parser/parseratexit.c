#include "parser.ih"

void parser_atexit(register Parser *pp, char *text)
{
    stack_pushVoidP(&pp->d_atexit_st, text);
}
