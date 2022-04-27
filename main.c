#include <stdio.h>
#include <string.h>

#include "miniminied.h"
#include "carg_parser.h"

char prompt[10];
bool isprompt = false;
bool iscommandmode = true;

int show_help() {
    printf("miniminied is a line-oriented text editor like GNU ed. This \n"
            "editor is made by minimize GNU ed. It is used to create, \n"
            "display,odify and otherwise manipulate text files, \n"
            "interactively. \n");
    return 0;
}

int show_version() {
    printf("miniminied \n"
    "Copyright (C) 2022 tomiy\n"
    "License GPLv2+: GNU GPL version 2 or later\n"
    "<http://gnu.org/licenses/gpl.html>\n"
    "This is free software: you are free to change and\n"
    "redistribute it.\n"
    "There is NO WARRANTY, to the extent permitted by law.\n");
    return 0;
}

int show_cargerrer() {
    //fprintf(stderr, "invalied option -- '%c'", hoge);
    fprintf(stderr, "Try './minied --help' for more information.");
    return 0;
}


int main( const int argc, const char * const argv[] ) {
    struct Arg_parser parser;
    struct Arg_parser *ap = &parser;
    struct Ap_option ap_options[] = {
        { 'h', "help", ap_no },
        { 'V', "version", ap_no },
        { 'p', "prompt", ap_yes},
        {  0, 0, ap_no },
    };
    if (ap_init(ap, argc, argv, ap_options)) {
        printf("hoge\n");
    }
    int argind = 0;
    while(argind < parser.data_size) {
        int code = parser.data[argind].code;
        char *pr = parser.data[argind].option;
        switch(code) {
            case 'h':
                show_help();
                return 0;
            case 'V':
                show_version();
                return 0;
            case 'p':
                strncpy(prompt, pr, 10);
                isprompt = true;
                break;
            // default:
                // TODO: print error
        }
        argind++;
    }
    puts("puts");
    printf("prompt = '%s'\n", prompt);
    return main_loop();
}
