#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ifarchive.h"
#include "carchive.h"
#include "dfarchive.h"
#include "design.h"

void append_data_line_by_line(FILE *sfp, FILE *dfp, char *filename, int files_count, files_header_t *files_header, int cond_state) {
    char buffer[8192]; // 8KB buffer
    for (int i = 0; i < files_count; i++) {
        if (cond_state != 0 ? DELETECOND : EXTRACTCOND) {             
            size_t remaining = files_header[i].file_size;
            while (remaining > 0) {
                size_t to_read = (remaining > sizeof(buffer)) ? sizeof(buffer) : remaining;
                size_t n = fread(buffer, 1, to_read, sfp);
                fwrite(buffer, 1, n, dfp);
                remaining -= n;
            }
        } else {
            fseek(sfp, files_header[i].file_size, SEEK_CUR); // Seek to start of data
        }
    }
}

bool check_file_existance(char *filename, files_header_t *files_header, int files_count) {
    for(int i=0; i < files_count; i++) {
        if(strcmp(files_header[i].filename, filename) == 0) {
            return true;
        }
    }
    return false;
}

void append_files_headers(FILE *dfp, char *filename, files_header_t *files_header, int files_count) {
    for(int i=0; i < files_count; i++) {
        if(strcmp(files_header[i].filename,filename) != 0) {
            fwrite(&files_header[i], sizeof(files_header_t), 1, dfp);
        }
    }
}

void d_file_from_archive(char *archive_name, char *filename) {
    // 1 - Open archive
    FILE *afp = fopen(archive_name,"r+b");
    if(afp == NULL) {
        printf("Failed to open such file \n");
        return;
    }

    // 2 - open a new tmp file
    FILE *atfp = fopen("arch.tmp","wb");
    if (atfp == NULL) {
        printf("Failed to open tmp file");
        return;
    }

    // 3 - Write archive header
    archive_header_t arch_header;
    fread(&arch_header, sizeof(archive_header_t), 1, afp);

    int files_count = arch_header.file_count;

    bool is_file_exist = false;

    if(files_count > 0) {
        files_header_t *files_header = get_files_headers(afp, files_count);

        is_file_exist = check_file_existance(filename, files_header, files_count);

        // Check if file is already in archive
        if(is_file_exist) {
            // Decrease file count
            arch_header.file_count--;
            fwrite(&arch_header, sizeof(archive_header_t), 1, atfp);

            // Write files headers after delete
            append_files_headers(atfp, filename, files_header, files_count);
            
            // Write data after delete
            append_data_line_by_line(afp, atfp, filename, files_count, files_header, DELETECODE);
            
            print_success("File deleted");
        } else {
            print_error("No such file to delete");
        }
    }

    // 5 - Close file
    fclose(afp);
    fclose(atfp);
    
    // 6 - Rewrite tmp file into the archive file
    if(is_file_exist) {
        remove(archive_name);
        rename("arch.tmp",archive_name);
    } else {
        remove("arch.tmp");
    }
}