
#include "../config.h"
#include "yodlpost.h"

void usage()
{
    char const *program = args_programName();

    fprintf(stderr,
"\n"
"Your Own Document Language: %s " TOPLEVEL_VERSION "\n"
"Usage: %s [options] index yodlout [out]\n"
"Where:\n"
"    [options]   options. Select from\n"
"       -x ext: extension of the out-files if different from the extension\n"
"               of `out' itself. If omitted, and `out' has no extension,\n"
"               ypp (Yodl Post Processor) is used.\n"
"    index:      the name of the index file generated by Yodl\n"
"    yodlout:    the name of the output file generated by Yodl\n"
"    [out]:      optional name of the file genreated by %s,\n"
"                stdout if omitted.\n"
"\n"
"The special tags in the index file are processed.\n"
"Normally, this program is run from a yodl2xxx script\n"
"\n",
    program,
    program,
    program
);

    exit(1);
}