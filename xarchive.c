#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "carchive.h"
#include "dfarchive.h"
#include "helper.h"
#include "design.h"


void e_file_from_archive(char *archive_name ,char *filename){
    // 1 - Open archive
    FILE *afp = fopen(archive_name,"r+b");
    if(afp == NULL) {
        printf("Failed to open such file \n");
        return;
    }

    // 2 - Open file to extract
    FILE *fp = fopen(filename,"wb");
    if(afp == NULL) {
        printf("Failed to open such file \n");
        return;
    }

    // 3 - Read archive header
    archive_header_t arch_header;
    fread(&arch_header, sizeof(archive_header_t), 1, afp);
    
    // 4 - Read files header

    bool is_file_exist = false;

    if(arch_header.file_count > 0) {
        files_header_t *files_header = get_files_headers(afp, arch_header.file_count);

        is_file_exist = check_file_existance(filename, files_header, arch_header.file_count);

        // Check if file is already in archive
        if(is_file_exist) {
            // Write data into file
            append_data_line_by_line(afp, fp, filename, arch_header.file_count, files_header, EXTRACTCODE);
            
            print_success("File Extracted");
        } else {
            print_error("No such file to extract");
        }
    }

    // 5 - Close file
    fclose(afp);
    fclose(fp);
}