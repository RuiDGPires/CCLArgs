#ifndef __CCLARGS_H__
#define __CCLARGS_H__

#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ARGS int argc, char *argv[]

#define BEGIN_PARSE_ARGS \
    for (int i = 0; i < argc; i++) {

#define ARG_FLAG(var, s) \
        if (argv[i][0] == '-' && strcmp(s, &argv[i][1]) == 0) \
        var = TRUE;

#define ARG_STRING(var, s) \
        if (strcmp(s, argv[i]) == 0) { \
            if (i + 1 < argc) { \
                var = argv[i + 1]; \
                i++; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define ARG_INT(var, s) \
        if (strcmp(s, argv[i]) == 0) { \
            if (i + 1 < argc) { \
                var = atoi(argv[i + 1]); \
                i++; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define ARG_FLOAT(var, s) \
        if (strcmp(s, argv[i]) == 0) { \
            if (i + 1 < argc) { \
                var = atof(argv[i + 1]); \
                i++; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define END_PARSE_ARGS }

#endif
