#include<stdio.h>
#include<stdlib.h>
#include<carchive.h>
#include<design.h>

void e_file_from_archive(char *archive_name ,char *filename){
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
}