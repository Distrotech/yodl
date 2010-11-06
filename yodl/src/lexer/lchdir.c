#include "lexer.ih"

void l_noChdir(Lexer *lp, char const *pathname)
{}

void l_chdir(Lexer *lp, char const *pathname)
{
// fprintf(stderr, "CHANGING WD\n");
 
    char resolved[PATH_MAX];
    bool cdOK =  realpath(media_filename(lp->d_media_ptr), resolved) != NULL;
    if (cdOK)
    {
        *(strrchr(resolved, '/') + 1) = 0;
        cdOK = chdir(resolved) == 0;
    }
    if (!cdOK)
    {
        char const *prefix = NULL;
        if (message_show(MSG_CRIT))
            prefix = "[Fatal] ";
        else if (message_show(MSG_WARNING))
            prefix = "";

        if (prefix != NULL)
            message("%s%s (%u): Can't chdir to `%s'", prefix,
                    message_filename(), message_lineno(), resolved);
    }
}






