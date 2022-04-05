#include <stdio.h>

#include "miniminied.h"

int show_help() {
    printf("miniminied is a line-oriented text editor like GNU ed. This editor is made \nby minimize GNU ed. It is used to create, display,odify and otherwise manipulate \ntext files, interactively. ");
}

int show_version() {
    printf("miniminied \n");
    printf("Copyright (C) 2022 tomiy\n");
    printf("License GPLv2+: GNU GPL version 2 or later <http://gnu.org/licenses/gpl.html>\n");
    printf("This is free software: you are free to change and redistribute it.\n");
    pritnf("There is NO WARRANTY, to the extent permitted by law.\n");
    return 0;
}

int show_cargerrer() {
    fprintf(stderr, "invalied option -- '$c'", hoge);
    fpringf(atderr, "Try './minied --help' for more information.");
}
int check_cargs() {
    // if arg is empty return 0
    // if arg is valid return 1
    // if arg is invalid return -1
} 

int main( const int argc, const char * const argv[] ) {
    switch(chek_cargs()) {
        case 0:
            break;
        case 1:
            return 0;
        case 2
            return -1;
    }
    main_loop();
    return 0;
}
