#include <stdio.h>
#include <stdlib.h>

#include "miniminied.h"
#include "carg_parser.h"

int ap_init(struct Arg_parser * const ap, const int argc, const char * const argv[], struct Ap_option ap_o[]) {
    ap->data = NULL;
    ap->error = NULL;
    ap->data_size = 0;
    ap->error_size = 0;
    int argind = 1;

    if (argc > 2 && !argv) { return -1; }
    
    while (argind < argc) {
        char ch1 = argv[argind][0];
        char ch2 = argv[argind][1];

        if (ch1 == '-' && ch2) {
            if (ch2 == '-') {
                parse_long_option(ap, argc, argv, argind, ap_o);
            } else {
                parse_short_option(ap, argc, argv, argind, ap_o);
            }
        } else { /* pass */ }
        argind++;
    }
    return 0;
}

void * ap_resize_buffer(void *buf, int size) {
    return realloc(buf, size); 
}

int push_back_record(struct Arg_parser * const ap, int code, char *option) {
    struct Arg_record *p;
    struct Arg_record *tmp = ap_resize_buffer(ap->data, (ap->data_size+1)*sizeof(struct Arg_record));
    if (!tmp) {
        return 0;
    } 
    p = tmp;
    p[ap->data_size].code = code;
    p[ap->data_size].option = option;
    ap->data = p;
    ap->data_size += 1;
    return p;
}

void parse_long_option(struct Arg_parser * const ap, const int argc, const char * const argv[], int argind, struct Ap_option ap_o[]) {
    char *long_option = argv[argind];
    char *ap_arg = argv[argind + 1];
    long_option++;
    long_option++;
    int code = 0;
    for (int i=0; ap_o[i].shortname != 0; i++) {
        if (!strcmp(ap_o[i].longname, long_option)) {
            code = ap_o[i].shortname;
            // printf("code = 0x%x:%c\n", code, code);
            if (ap_o[i].has_arg == ap_no) {
                push_back_record(ap, code, NULL);
            } else {
                push_back_record(ap, code, ap_arg);
                // printf("option: %s\n", ap_arg);
            }
            return;
        }
    }
    printf("ed: unrecognized option '--%s'\n", long_option);
    exit(1);
    return;
}

void parse_short_option(struct Arg_parser * const ap, const int argc, const char * const argv[], int argind, struct Ap_option ap_o[]) {
    char *short_option = argv[argind];
    char *ap_arg = argv[argind+1];
    short_option++;
    char ch1 = short_option[0];
    char ch2 = short_option[1];
    int code = 0;
    if (ch2 != '\0') {
        printf("ed: invalid option -- '%c'\n", ch2);
        exit(1);
    } else {
        for (int i = 0; ap_o[i].shortname != 0; i++) {
            if (ap_o[i].shortname == ch1) {
                code = ch1;
                // printf("code  = 0x%x:%c\n", code, code);
                if (ap_o[i].has_arg == ap_no) {
                    push_back_record(ap, code, NULL);
                } else {
                    push_back_record(ap, code, ap_arg);
                    // printf("optiont: %s\n", ap_arg);
                }
                return;
            }
        }
        printf("ed: invalid option --'%c'\n", ch1);
        exit(1);
    }
}

