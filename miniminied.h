

enum Bool { false = 0, true = 1 };
typedef enum Bool bool;

extern char prompt[10];
extern bool isprompt;
extern bool iscommandmode;

/* defined in main_loop.c */
int exec_command();
int main_loop();
