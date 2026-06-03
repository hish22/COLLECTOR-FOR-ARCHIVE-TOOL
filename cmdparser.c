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
            if(cmp_magic_number(archive_name)) {
                i_file_into_archive(archive_name,filename);
            } else {
                print_error("Failed to open cfat archive file.");
            }
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
            if(cmp_magic_number(archive_name)) {
                d_file_from_archive(archive_name, filename);
            } else {
                print_error("Failed to open cfat archive file.");
            }
            break;

        case 'l':
            if(cmp_magic_number(archive_name)) {
                list_files_info(archive_name);
            } else {
                print_error("Failed to open cfat archive file.");
            }
            break;

        case 'x':
            if(cmp_magic_number(archive_name)) {
                e_file_from_archive(archive_name,filename);
            } else {
                print_error("Failed to open cfat archive file.");
            }
            break;

        case 'n':
            if(cmp_magic_number(archive_name)) {
                archive_file_count(archive_name);
            } else {
                print_error("Failed to open cfat archive file.");
            }
            break;

        case 'r':
            if(cmp_magic_number(archive_name)) {
                r_file_with_file(archive_name,filename,sec_filename);
            } else {
                print_error("Failed to open cfat archive file.");
            }
            break;

        default:
            print_error("No such Command");
            break;
        }
    }

}