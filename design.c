#include <stdio.h>

#include "design.h"

// 1. Print program header 
void print_program_header() {
    printf("\n%s==================================================%s\n", CYAN, COLOR_RESET);
    printf("%s||%s %s%s   CFAT - COLLECTOR FOR ARCHIVE TOOL   %s %s||\n", CYAN, COLOR_RESET, BG_CYAN, WHITE, COLOR_RESET, CYAN);
    printf("%s==================================================%s\n", CYAN, COLOR_RESET);
}

// 2. Foreground colors 
void print_FG(const char *text, const char *FG_color) {
    printf("%s%s%s", FG_color, text, COLOR_RESET);
}

// 3. Background colors
void print_BG(const char *text, const char *BG_COLOR) {
    printf("%s%s%s", BG_COLOR, text, COLOR_RESET);
}

// 4. Full color 
void print_FullColor(const char *text, const char *FG_color, const char *BG_color) {
    printf("%s%s%s%s", BG_color, FG_color, text, COLOR_RESET);
}

// 5.when program sucsesful
void print_error(const char *message) {
    printf("\n\033[41m\033[1;37m [ ERROR ] \033[0m \033[1;31m%s\033[0m\n", message);
}

// 6.when program are error
void print_success(const char *message) {
    printf("\n\033[42m\033[1;37m [ SUCCESS ] \033[0m \033[1;32m%s\033[0m\n", message);
}

// 7. print_copyright
void print_copyright() {
printf("\n%s[CFAT Tool] Open-source software. Free to use and modify.%s\n\n", BLACK, COLOR_RESET);
}

// 8.print logo
void print_logo() {
    printf("%s", CYAN);
    printf("     .--------.     \n");
    printf("    /  .-''-.  \\    \n");
    printf("   /  /  __  \\  \\   \n");
    printf("  |  |  [CFAT] |  |  \n");
    printf("   \\  \\  `--'  /  /   \n");
    printf("    \\  `-__-'  /    \n");
    printf("     `--------'     \n");
    printf("%s", COLOR_RESET);
}