#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define BUFSIZE 256

int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Check if the file exists and get its size using stat()
    struct stat file_info;
    if (stat(argv[1], &file_info) != 0) {
        fprintf(stderr, "File does not exist: %s\n", argv[1]);
        return -1;
    }

    // Print the file size in bytes
    printf("The size of the file is: %ld bytes.\n", file_info.st_size);

    return 0;
}
