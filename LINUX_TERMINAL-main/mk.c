#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char* argv[])
{
	if(argc > 3){
		fprintf(stderr, "ERROR: Expected max 1 argument, recieved %d \n", argc-1);
		printf("USAGE: [-v]\n");
		exit(EXIT_FAILURE);		
	}
	if(!strcmp(argv[1], "-v")){
		printf("%s", argv[2]);
		int status = mkdir(argv[2], 0777);
		if(status){
			printf("Error");
		}
		else{
			printf("Created successfully");
		}		
	}
	else{
		int status = mkdir(argv[1],  0777);
		if(!status){
			printf("Created successfully");
		}
		else{
			printf("Error");
		}
				
	}
	return 0;
}
