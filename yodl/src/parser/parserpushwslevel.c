#include "parser.ih"

void parser_push_ws_level(register Parser *pp, int value)
{
    stack_pushInt(&pp->d_ws_level_st, pp->d_ws_level);
    p_set_ws_level(pp, pp->d_ws_level = value);
}
