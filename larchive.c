#include <stdio.h>
#include <stdlib.h>
#include "design.h"
#include "ifarchive.h"
#include "carchive.h"

//FUNCTHION OF ALL FILES AND THEIR SIZE
void list_files_info(char *archive_name) {
    
    //1.OPEN THE ARCHIVE FILE
    FILE *fh_arch = fopen(archive_name, "rb");
    if (fh_arch == NULL) {
        print_error("Failed to list files.\n");
        return;
    }


    //READ THE ARCHIVE FILE
    archive_header_t archive_header;
    fread(&archive_header, sizeof(archive_header_t), 1, fh_arch);

    void print_logo();

    //PRINT TABLE HEADR
    printf("\n%s%-30s %-15s%s\n", CYAN, "File Name", "Size (Bytes)", COLOR_RESET);
    printf("-----------------------------------------------\n");

    files_header_t *f_header = get_files_headers(fh_arch, archive_header.file_count);

   //LOOP INSIDE ARCHIVE
    for(int i=0; i < archive_header.file_count; i++) {
        printf("%-30s %-15u\n", f_header[i].filename, f_header[i].file_size);
    }

    //PRINT TABLE DOWN
    printf("-----------------------------------------------\n");
    print_success("Archive contents listed successfully.");
    
    fclose(fh_arch);
    print_logo();
}

