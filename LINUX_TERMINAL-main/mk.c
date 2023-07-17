#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    // Check the number of command-line arguments
    if (argc > 3) {
        fprintf(stderr, "ERROR: Expected max 1 argument, received %d \n", argc-1);
        printf("USAGE: [-v]\n");
        exit(EXIT_FAILURE);
    }

    // If the argument is "-v", create the directory and print the result
    if (!strcmp(argv[1], "-v")) {
        printf("%s", argv[2]);
        int status = mkdir(argv[2], 0777);
        if (status) {
            printf("Error");
        }
        else {
            printf("Created successfully");
        }
    }
    else {
        // Create the directory and print the result
        int status = mkdir(argv[1], 0777);
        if (!status) {
            printf("Created successfully");
        }
        else {
            printf("Error");
        }
    }
    return 0;
}
