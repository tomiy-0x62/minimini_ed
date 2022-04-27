
#include <stdio.h>

#include "miniminied.h"

int exec_command() {

}

void show_prompt() {
    if (isprompt) {
        if(prompt[0] == '\0') {
            printf("*");
        } else {
            printf("%.10s", prompt);
        }
    }
}

int main_loop() {
    char linebuf[128]; 
    while(1) {
    if (iscommandmode) { show_prompt(); }
    // get line
    fgets(linebuf, 128, stdin);
    printf("read '%.128s'\n", linebuf);
    }
    
    return 0;
}
