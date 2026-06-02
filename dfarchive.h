#ifndef DF_ARCHIVE
#define DF_ARCHIVE

#define DELETECOND strcmp(files_header[i].filename, filename) != 0
#define EXTRACTCOND strcmp(files_header[i].filename, filename) == 0

#define DELETECODE 1
#define EXTRACTCODE 0

void append_data_line_by_line(FILE *sfp, FILE *dfp, char *filename, int files_count, files_header_t *files_header, int cond_state);

bool check_file_existance(char *filename, files_header_t *files_header, int files_count);

#endif