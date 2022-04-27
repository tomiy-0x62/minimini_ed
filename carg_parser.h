
struct Arg_record {
    int code;     // 'E', 'P'
    char *option; // "ed>"
};

struct Arg_parser {
    struct Arg_record *data;
    char *error;
    int data_size;
    int error_size;
};

enum ap_has_arg {
    ap_no,
    ap_yes,
};

struct Ap_option {
    int shortname;
    char *longname;
    enum ap_has_arg has_arg;
};

int ap_init(struct Arg_parser * const ap, const int argc, const char * const argv[], struct Ap_option ap_o[]);
void *ap_resize_buffer(void *ap, int size);
int push_back_record(struct Arg_parser * const ap, int code, char *option);
void parse_long_option(struct Arg_parser * const ap, const int argc, const char * const argv[], int argind, struct Ap_option ap_o[]);
void parse_short_option(struct Arg_parser * const ap, const int argc, const char * const argv[], int argind, struct Ap_option ap_o[]);
