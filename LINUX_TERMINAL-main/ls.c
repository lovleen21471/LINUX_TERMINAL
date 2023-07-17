#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    // Variable Declarations
	struct dirent *dq; // Directory entry structure
	DIR *dr = opendir("."); // Open current directory
	if(dr == NULL)
	{
		printf("Error"); // Print error if directory cannot be opened
		return 0;
	}
	char **s; // Array of strings to store file names
	int i = 0; // Index variable for file name array
	
    // Reading directory contents
	if(argv[1] == "-r"){
		while((dq = readdir(dr))!= NULL){
			s[i] = dq->d_name; // Store file name in the array
			i++;
		}
		while(i >=0){
			printf("%s\t", s[i]); // Print file names in reverse order
			i--;
		}
	}	
	if(argv[1] == "-A")
	{	while((dq = readdir(dr))!= NULL){
			if(!strcmp(dq->d_name, ".") || !strcmp(dq->d_name, ".."))
				continue; // Skip current directory and parent directory
			printf("%s\t", dq->d_name); // Print file name
		}
	}
	else
	{
		while((dq = readdir(dr))!= NULL){
			printf("%s\t", dq->d_name); // Print file name
		}
	}
	
    // Cleanup and return
	closedir(dr); // Close the directory
	return 0; // Exit the program
}
