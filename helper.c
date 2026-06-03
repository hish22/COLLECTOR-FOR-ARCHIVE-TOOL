#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "carchive.h"

char* get_file_name(char *filename) {
    // Find the last forward slash
    char *last_slash = strrchr(filename, '/');
    
    // Find the last backward slash (for Windows paths)
    char *last_backslash = strrchr(filename, '\\');
    
    // Determine which one occurred last
    char *last_separator = (last_slash > last_backslash) ? last_slash : last_backslash;
    
    // If a separator was found, return the part after it
    if (last_separator != NULL) {
        return last_separator + 1;
    }
    
    return filename;
}

bool cmp_magic_number(char *archive_file) {
    // Open archive
    FILE *afp = fopen(archive_file,"rb");
    if(afp == NULL) {
        return false;
    }

    // Read the archive header
    archive_header_t arch_header;
    fread(&arch_header, sizeof(archive_header_t), 1, afp);

    if(arch_header.magic_number == MAGIC_NUMBER) {
        return true;
    }

    return false;
}