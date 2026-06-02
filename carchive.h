#ifndef C_ARCHIVE
#define C_ARCHIVE
typedef struct archive_header{
    const int magic_number;
    unsigned int version_number;
    unsigned int file_count;
}archive_header_t;

typedef struct files_header{
    // unsigned int offset;
    char filename[80];
    unsigned int file_size;
}files_header_t;
#endif