#ifndef IF_ARCHIVE
#define IF_ARCHIVE

files_header_t* get_files_headers(FILE *sfp, int file_count);

void write_new_file_header(FILE *fp, int file_size, char* filename);

void append_file_content(FILE *fp, char *filename, size_t filesize);

// void append_data_line_by_line(FILE *sfp, FILE *dfp, char *filename, int files_count, files_header_t *files_header);


#endif