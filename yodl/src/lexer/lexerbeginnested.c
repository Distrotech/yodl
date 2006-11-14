#include "lexer.ih"

/*

    When nested evaluation takes place, the current empty index of the media
stack is pushed and d_empty is set to the current d_media_st size.

    An empty media stack has size 0, which is just before the first element to
push. So, we'll set d_empty to the current size, and then push the string to
evaluate.

    d_empty_size, therefore, is in the world of counts, not offsets.

*/

void lexer_begin_nested(register Lexer *lp, register char const *txt)
{
    stack_pushInt(&lp->d_empty_st, lp->d_empty_size);
    lp->d_empty_size = stack_size(&lp->d_media_st);

    if (message_show(MSG_INFO))
        message("Nested media begins at stack size %u", lp->d_empty_size);

    l_push_level(lp, txt);
}
