#ifndef DESIGN
#define DESIGN

// text colors
#define RED             "\033[1;31m"
#define GREEN           "\033[1;32m"
#define BLACK           "\033[1;30m"
#define YELLOW          "\033[1;33m"
#define BLUE            "\033[1;34m"
#define MAGENTA         "\033[1;35m"
#define CYAN            "\033[1;36m"
#define WHITE           "\033[1;37m"
#define COLOR_RESET     "\033[0m"

// background colors
#define BG_BLACK        "\033[40m"
#define BG_RED          "\033[41m"
#define BG_GREEN        "\033[42m"
#define BG_YELLOW       "\033[43m"
#define BG_BLUE         "\033[44m"
#define BG_WHITE        "\033[47m"
#define BG_CYAN         "\033[46m"

void print_program_header();

void print_FG(const char *text, const char *FG_color);

void print_BG(const char *text, const char *BG_COLOR);

void print_FullColor(const char *text, const char *FG_color, const char *BG_color);

void print_error(const char *message);

void print_success(const char *message);

void print_copyright();

void print_logo();

#endif