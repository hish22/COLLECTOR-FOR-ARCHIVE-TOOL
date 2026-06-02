#include <stdio.h>

#include "ifarchive.h"
#include "carchive.h"
#include "dfarchive.h"
#include "design.h"

#define stat_t struct stat

void append_files_headers_with_replace(FILE *dfp, char *f_to_replace, char* r_file, files_header_t *files_header, int files_count, int r_file_size) {
    for(int i=0; i < files_count; i++) {
        if(strcmp(files_header[i].filename,f_to_replace) != 0) {
            fwrite(&files_header[i], sizeof(files_header_t), 1, dfp);
        } else {
            write_new_file_header(dfp, r_file_size, r_file);
        }
    }
}

void r_file_with_file(char *archive_name, char *f_to_replace, char *r_file) {
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


    // 3 - Get file stat
    stat_t file_stat;
    if(stat(r_file,&file_stat) != 0) {
        printf("Failed to get file stat \n");
        fclose(afp);
        fclose(atfp);
        return;
    }

    // 3 - Read archive header
    archive_header_t arch_header;
    fread(&arch_header, sizeof(archive_header_t), 1, afp);
    fwrite(&arch_header, sizeof(archive_header_t), 1, atfp);
    // 4 - Replace files
    bool is_file_exist = false;

    if(arch_header.file_count > 0) {
        files_header_t *files_header = get_files_headers(afp, arch_header.file_count);

        is_file_exist = check_file_existance(f_to_replace, files_header, arch_header.file_count);

        // Check if file is already in archive
        if(is_file_exist) {
            // Write files headers after delete
            append_files_headers_with_replace(atfp, f_to_replace, r_file, files_header, arch_header.file_count, file_stat.st_size);
            
            // Write data after delete
            append_file_content(atfp, r_file, file_stat.st_size);
            append_data_line_by_line(afp, atfp, f_to_replace, arch_header.file_count, files_header, DELETECODE);
            
            print_success("File replaced");
        } else {
            print_error("No such file to replace");
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