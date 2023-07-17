#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    // Check the number of command-line arguments
	if (argc > 2) {
		fprintf(stderr, "ERROR: Expected max 1 argument, received %d.\n", argc-1);
		printf("USAGE: %s [-u] [-R]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

    // If no argument is provided, display current time in local format
	if (argc == 1) {
		time_t time1;
		time(&time1);
		struct tm *information = localtime(&time1);
		char string[100];
		strftime(string, 100, "%a %b %d %H:%M:%S %Z %Y", information);
		printf("%s\n", string);
	}
	else {
        // Handle different command-line arguments
		if (strcmp(argv[1], "-u") == 0) {
		    // Display current time in UTC format
			time_t time1;
			time(&time1);
			struct tm *information = gmtime(&time1);
			char string[100];
			strftime(string, 100, "%a %b %d %H:%M:%S %Z %Y", information);
			printf("%s\n", string);
		}
		else if (strcmp(argv[1], "-R") == 0) {
		    // Display current time in RFC 2822 format
			time_t time1;
			time(&time1);
			struct tm *information = localtime(&time1);
			char string[100];
			strftime(string, 100, "%a %b %d %H:%M:%S %z", information);
			printf("%s\n", string);
		}
		else {
			fprintf(stderr, "ERROR: Invalid argument: %s\n", argv[2]);
			printf("USAGE:argv[1] [-u] [-R]\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
