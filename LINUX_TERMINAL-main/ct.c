#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    // Check command-line arguments
	if(!strcmp(argv[1], "-n")){
	    // Open file for reading
		FILE *fr;
		fr = fopen(argv[2], "r");
		char c;
		int l = 1; // Line number counter
		int q = 0; // Flag to track first character in a line

        // Read file character by character
		while((c = fgetc(fr)) != EOF){
			if(q == 0){
				printf("\t%d", l); // Print line number at the beginning of a line
				l++;
				q = 1;
			}
			printf("%c", c); // Print character

            // If newline character is encountered, print line number and increment it
			if(c == '\n'){
				printf("\t%d ", l);
				l++;
			}
		}
	}
	if(!strcmp(argv[1] , "-u")){
	    // Open file for reading
		FILE *fr;
		fr = fopen(argv[2], "r");
		char c;
		
        // Read file character by character and print each character
		while((c = fgetc(fr)) != EOF){
			printf("%c", c);
		}
	}
	else{
	    // Open file for reading
		FILE *fr;
		fr = fopen(argv[1], "r");
		char c;
		
        // Read file character by character and print each character
		while((c = fgetc(fr)) != EOF){
			printf("%c", c);
		}
	}
	return 0; // Exit the program
}
