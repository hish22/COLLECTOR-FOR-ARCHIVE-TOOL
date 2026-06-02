#include <stdio.h>

#include "carchive.c"
#include "ifarchive.c"
#include "dfarchive.c"
#include "narchive.c"
#include "design.c"
#include "larchive.c"
#include "helper.c"
#include "xarchive.c"
#include "rarchive.c"

void parser(int argv, char **args) {
    // 'i' -> Inseart new file
    // 'c' -> create new archive file
    // 'h' -> show tool commands and info
    // 'd' -> delete specific file content
    // 'l' -> list files from archive
    // 'x' -> extract file or all files from archive
    // 'n' -> file coount
    if(argv < 2) {
        printf("Error: No command provided. Use -h for help.\n");
        return;
    }

    char *flag = args[1];
    char *archive_name = args[2];
    char *filename = args[3];
    char *sec_filename = args[4];

    if(flag[0] == '-') {
        switch (flag[1]) {
        case 'i':
            i_file_into_archive(archive_name,filename);
            break;
        
        case 'c':
            create_archive_file(archive_name);
            break;

        case 'h':
            print_program_header();
            printf("Usage: cfat [command] [archive] [filename]\n");
            printf("-c [archive] : Create archive\n");
            printf("-i [archive] [filename] : Insert file\n");
            printf("-d [archive] [filename] : Delete file\n");
            printf("-l [archive] : List contents\n");
            printf("-x [archive] [filename] : Extract\n");
            printf("-n [archive] : Files Count\n");
            printf("-r [archive] [filename to replace] [replace filename] : Replace File\n");
            printf("\n[archive] \n ");
            print_copyright();  
            break;

        case 'd':
            d_file_from_archive(archive_name, filename);
            break;

        case 'l':
            list_files_info(archive_name);
            break;

        case 'x':
            e_file_from_archive(archive_name,filename);
            break;

        case 'n':
            archive_file_count(archive_name);
            break;

        case 'r':
            r_file_with_file(archive_name,filename,sec_filename);
            break;

        default:

            break;
            
        }
    }

}