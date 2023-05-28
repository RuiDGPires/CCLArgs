#include <stdio.h>
#include "include/cclargs.h"

int main(ARGS) {
    int is_verbose = FALSE, is_static = FALSE, j = FALSE;
    const char *filename = "None";

    BEGIN_PARSE_ARGS
        ARG_SHORT_FLAG(j, "j")
        ARG_FLAG(is_verbose, "v", "verbose")
        ARG_FLAG(is_static, "s", "static")
        ARG_STRING(filename, "-o")
    END_PARSE_ARGS

    printf("verbose: %d\nstatic: %d\nj: %d\nfilename: %s\n", is_verbose, is_static, j, filename);
}
