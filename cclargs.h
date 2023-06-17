#ifndef __CCLARGS_H__
#define __CCLARGS_H__

#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ARGS int argc, char *argv[]

#define BEGIN_PARSE_ARGS(fmt, args...) { /* Receives a format string for the mandatory arguments */ \
    char *_args_fmt = fmt;\
    int _argi = 0; \
    void *__args[] = {args}; \
    for (int _i = 1; _i < argc; _i++) { \
        int flag_len = strlen(argv[_i]); \
        int _flag_read = FALSE; \
        for (int _j = 1; _j < flag_len; _j++) {

#define END_PARSE_ARGS \
        } \
        if (_flag_read == FALSE && _args_fmt[0] != '\0') { \
            int read = sscanf(argv[_i], _args_fmt, __args[_argi++]); \
            if (read == 0) { \
                fprintf(stderr, "Invalid argument\n"); \
                exit(0); \
            } \
            while (_args_fmt[0] != '\0' && _args_fmt[0] != ' ') {\
                _args_fmt = &_args_fmt[1];\
            } \
            if (_args_fmt[0] != '\0') {\
                _args_fmt = &_args_fmt[1];\
            } \
\
    } \
    _next: \
 \
    } \
    if (_args_fmt[0] != '\0') {\
        fprintf(stderr, "Missing argument\n"); \
        exit(1); \
    } \
}

#define ARG_SHORT_FLAG(var, s) \
        if ((argv[_i][0] == '-' && strchr(s, argv[_i][_j]))) {\
            var = TRUE; \
            _flag_read = TRUE; \
        }

#define ARG_FLAG(var, s, full) \
        if ((argv[_i][0] == '-' && strchr(s, argv[_i][_j])) || \
            (_j == 1 && argv[_i][0] == '-' && argv[_i][1] == '-' && strcmp(full, &argv[_i][2]) == 0)) {\
            var = TRUE; \
            _flag_read = TRUE; \
        }

#define ARG_STRING(var, s) \
        if (_j == 1 && strcmp(s, argv[_i]) == 0) { \
            if (_i + 1 < argc) { \
                var = argv[_i + 1]; \
                _i++; \
                goto _next; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define ARG_INT(var, s) \
        if (_j == 1 && strcmp(s, argv[_i]) == 0) { \
            if (_i + 1 < argc) { \
                var = atoi(argv[_i + 1]); \
                _i++; \
                goto _next; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define ARG_FLOAT(var, s) \
        if (_j == 1 && strcmp(s, argv[_i]) == 0) { \
            if (_i + 1 < argc) { \
                var = atof(argv[_i + 1]); \
                _i++; \
                goto _next; \
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        }

#define ARG_MULTI(s, full, fmt, args...) \
    if (_j == 1 && (argv[_i][0] == '-' && strcmp(s, &argv[_i][1]) == 0) || \
        (argv[_i][0] == '-' && argv[_i][1] == '-' && strcmp(full, &argv[_i][2]) == 0)) { \
        char *__fmt = fmt; \
        void *__args[] = {args};\
        int _k = _i + 1; \
        int _argi = 0; \
        for (; strlen(__fmt) != 0; _k++) {\
            if (_k < argc) { \
                int read = sscanf(argv[_k], __fmt, __args[_argi++]); \
                if (read == 0) { \
                    fprintf(stderr, "Invalid value for argument: %s\n", s); \
                    exit(1); \
                } \
                while (strlen(__fmt) > 0 && __fmt[0] != ' ') {\
                    __fmt = &__fmt[1];\
                } \
                if (__fmt[0] != '\0') \
                    __fmt = &__fmt[1];\
            } else { \
                fprintf(stderr, "Missing value for argument: %s\n", s); \
                exit(1); \
            } \
        } \
        _i = _k - 1; \
        goto _next; \
    }

#endif
