#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "carchive.h"
// Vaildate name length
#define name_length_in_range strlen(archive_name) < 80 && strlen(archive_name) > 0

// Create new archive file
void create_archive_file(char *archive_name) {
    archive_header_t arch = {
        0x062AB188,
        1,
        0
    };

    if (name_length_in_range) {
        char t_archive_name_buf[80];

        sprintf(t_archive_name_buf,"%s.cfat",archive_name);

        FILE *arch_file = fopen(t_archive_name_buf,"wb");

        if(arch_file != NULL) {
            fwrite(&arch,sizeof(archive_header_t), 1, arch_file);
            fclose(arch_file);
            printf("Archive %s created \n",t_archive_name_buf); // temp
        } else {
            printf("Failed to create %s archive \n",t_archive_name_buf);
        }
    } else {
        printf("Failed to create archive, error: %s \n","Name length must be greater than 0 or less than 80");
    }

}