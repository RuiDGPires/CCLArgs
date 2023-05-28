#include <stdio.h>
#include "include/cclargs.h"

int main(ARGS) {
    int is_verbose = FALSE;
    const char *filename;

    BEGIN_PARSE_ARGS
        ARG_FLAG(is_verbose, "v")
        ARG_STRING(filename, "-o")
    END_PARSE_ARGS

    printf("%d | %s\n", is_verbose, filename);
}
