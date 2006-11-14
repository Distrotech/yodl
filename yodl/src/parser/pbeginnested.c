#include "parser.ih"

void p_begin_nested(register Parser *pp, HANDLER_SET_ELEMENTS newSet)
{
                                        /* set up handler set to use        */
    stack_pushVoidP(&pp->d_handler_st, pp->d_handler);
    pp->d_handler = ps_handlerSet[newSet];

                                        /* save the  inserter               */
    stack_pushVoidP(&pp->d_insert_st, pp->d_insert);

    switch (newSet)
    {
        case COLLECT_SET:
            stack_pushVoidP(&pp->d_string_st, pp->d_string_ptr);
            pp->d_string_ptr = string_new(0);

            pp->d_insert = p_insert_no_chartab_string;
        break;

        case DEFAULT_SET:
            stack_pushVoidP(&pp->d_string_st, pp->d_string_ptr);
            pp->d_string_ptr = string_new(0);

            pp->d_insert =
                    pp->d_insert = chartab_isActive() ?
                        p_insert_chartab_string
                    :
                        p_insert_no_chartab_string;
        break;

        case IGNORE_SET:
            pp->d_insert = p_insert_nothing;
        break;

        case NOTRANS_SET:
            parser_suppress_chartab(pp);
        // FALL THROUGH

        case NOEXPAND_SET:
            parser_push_ws_level(pp, 0);
        break;

        default:
        break;
    }
}
