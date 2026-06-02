#include<stdio.h>
#include<stdlib.h>
#include"design.h"
#include"carchive.h"


// FILE COUNTER
void archive_file_count(char* archive_name) {
    
    FILE* fh_arch = fopen(archive_name, "rb");
    if (fh_arch == NULL) {
        print_error("Archive is Embty\n");
        return;
    }

    // Read the main archive header
    archive_header_t arch_header;
    fread(&arch_header, sizeof(archive_header_t), 1, fh_arch);
    printf("\n%sTotal Files in Archive:%s %u\n", CYAN, COLOR_RESET, arch_header.file_count);
    fclose(fh_arch);
    print_logo();
}