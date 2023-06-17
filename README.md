# CCLArgs

A simple header library for parsing command line arguments in C.

## Usage

Simply download `cclargs.h` to an appropriate place in the project and include it on your main file.
---

Example:
```C
#include <stdio.h>
#include "cclargs.h"

int main(ARGS) {
    int is_verbose = FALSE, is_static = FALSE, j = FALSE;
    const char *filename = "None";

    int val1, val3;
    char val2[100];

    int mandatory = 0;
    BEGIN_PARSE_ARGS("%d", &mandatory)
        ARG_SHORT_FLAG(j, "j")
        ARG_FLAG(is_verbose, "v", "verbose")
        ARG_FLAG(is_static, "s", "static")
        ARG_STRING(filename, "-o")
        ARG_MULTI("m", "multiple", "%d %s %d", &val1, val2, &val3)
    END_PARSE_ARGS

    printf("verbose: %d\nstatic: %d\nj: %d\nfilename: %s\n", is_verbose, is_static, j, filename);
    printf("val1: %d\nval2: %s\nval3: %d\n", val1, val2, val3);
    printf("Mandatory: %d\n", mandatory);
}

```
