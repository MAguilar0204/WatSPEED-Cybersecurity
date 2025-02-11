#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 256

int main(int argc, char** argv) {
    
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    if (access(argv[1], F_OK) != 0) {
        fprintf(stderr, "File does not exist: %s\n", argv[1]);
        return -1;
    }
 
    char cmd[BUFSIZE];
    snprintf(cmd, BUFSIZE, "wc -c < %s", argv[1]);

    system(cmd);

    return 0;
}

