#ifndef __CCLARGS_H__
#define __CCLARGS_H__

#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ARGS int argc, char *argv[]

#define BEGIN_PARSE_ARGS \
    for (int _i = 0; _i < argc; _i++) { \
    int flag_len = strlen(argv[_i]); \
    for (int _j = 1; _j < flag_len; _j++) {

#define ARG_SHORT_FLAG(var, s) \
        if ((argv[_i][0] == '-' && strchr(s, argv[_i][_j]))) \
            var = TRUE;

#define ARG_FLAG(var, s, full) \
        if ((argv[_i][0] == '-' && strchr(s, argv[_i][_j])) || \
            (argv[_i][0] == '-' && argv[_i][1] == '-' && strcmp(full, &argv[_i][2]) == 0)) \
            var = TRUE;

#define ARG_STRING(var, s) \
        if (strcmp(s, argv[_i]) == 0) { \
            if (_i + 1 < argc) { \
                var = argv[_i + 1]; \
                _i++; \
                break; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define ARG_INT(var, s) \
        if (strcmp(s, argv[_i]) == 0) { \
            if (_i + 1 < argc) { \
                var = atoi(argv[_i + 1]); \
                _i++; \
                break; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define ARG_FLOAT(var, s) \
        if (strcmp(s, argv[_i]) == 0) { \
            if (_i + 1 < argc) { \
                var = atof(argv[_i + 1]); \
                _i++; \
                break; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define END_PARSE_ARGS }}

#endif
