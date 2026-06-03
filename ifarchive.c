#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#include "carchive.h"
#include "helper.h"
#include "design.h"

#define stat_t struct stat

void write_new_file_header(FILE *fp, int file_size, char* filename) {
    files_header_t new_file_header;
    memset(&new_file_header, 0, sizeof(files_header_t));
    new_file_header.file_size = file_size;
    strncpy(new_file_header.filename, get_file_name(filename), 80);

    fwrite(&new_file_header, sizeof(files_header_t), 1, fp);
}

void append_file_content(FILE *fp, char *filename, size_t filesize) {
    FILE *fp_content = fopen(filename,"rb");
    if(fp_content == NULL) {
        printf("Failed to append file content \n");
        return;
    }

    // Move to end of file to append data
    fseek(fp, 0, SEEK_END);

    char buf[4096];
    size_t bytes_read;
    while((bytes_read = fread(buf, 1, sizeof(buf), fp_content)) > 0) {
        fwrite(buf, 1, bytes_read, fp);
    }
    fclose(fp_content);
}

files_header_t* get_files_headers(FILE *sfp, int files_count) {
    files_header_t *files_header = malloc(sizeof(files_header_t) * files_count);
    fread(files_header, sizeof(files_header_t), files_count, sfp);
    return files_header;
}

void i_file_into_archive(char *archive_name, char *filename) {
    // 1 - Open archive
    FILE *afp = fopen(archive_name,"r+b");
    if(afp == NULL) {
        print_error("Failed to open such file \n");
        return;
    }

    // 2 - open a new tmp file
    FILE *atfp = fopen("arch.tmp","wb");
    if (atfp == NULL) {
        print_error("Failed to open tmp file");
        fclose(afp);
        fclose(atfp);
        return;
    }

    // 3 - Get file stat
    stat_t file_stat;
    if(stat(filename,&file_stat) != 0) {
        print_error("Failed to get file stat \n");
        remove("arch.tmp");
        return;
    }

    // 4 - Update header file count
    archive_header_t arch_header;
    fread(&arch_header, sizeof(archive_header_t), 1, afp);
    arch_header.file_count++;

    // 5 - write to tmp file
    fwrite(&arch_header, sizeof(archive_header_t), 1, atfp);

    // 6 - Write exist file header
    int files_count = arch_header.file_count - 1;
        if(files_count > 0) {
            files_header_t *files_header = get_files_headers(afp, files_count);
            for(int i=0; i < files_count; i++) {
                fwrite(&files_header[i], sizeof(files_header_t), 1, atfp);
        }
    }

    // 7 - Write new file header
    write_new_file_header(atfp, file_stat.st_size, filename);

    // 8 - Append data of exist archive
    fseek(atfp,0,SEEK_END);
    char buf[4096];
    size_t bytes_read;
    while((bytes_read = fread(buf, 1, sizeof(buf), afp)) > 0) {
        fwrite(buf, 1, bytes_read, atfp);
    }

    // 9 - Append file data
    append_file_content(atfp, filename, file_stat.st_size);

    // 10 - Close file
    fclose(afp);
    fclose(atfp);

    // 11 - Rewrite tmp file into the archive file
    remove(archive_name);
    int r_state = rename("arch.tmp",archive_name);
    if(!r_state) {
        print_success("File inserted");
    }

}