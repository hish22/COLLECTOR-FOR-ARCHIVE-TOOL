#include <stdio.h>
#include <string.h>

#include <string.h>

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