#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    // Print the number of command-line arguments and the values of argv[0] and argv[1]
	printf("%d %c %c", argc, argv[0], argv[1]);

    // If the argument is "-i", prompt the user for confirmation before deletion
	if(!strcmp(argv[1], "-i")){
		printf("Do you want to delete the file Y/N:");
		char a;
		scanf("%c", &a);
		
        // Check user input for deletion confirmation
		if(a == 'Y'){
			int t = unlink(argv[2]); // Delete the file
			
		}
		if(a == 'N'){
			// Do nothing if deletion is not confirmed
		}
		else{
		    printf("Not valid input");
		}
	}
    
    // If the argument is "-v", delete the file and print the result with verbose output
	if(!strcmp(argv[1], "-v")){
		int t = unlink(argv[1]); // Delete the file
		if(!t){
			printf("Enter a valid input\n");
		}
		else{
			printf("Removed");
		}
	} 
    
    // If none of the above conditions match, delete the file and print the result
	else{
		int t = unlink(argv[1]); // Delete the file
		if(!t){
			printf("Enter a valid input\n");
		}
		else{
			printf("Removed successfully");
		}		
	}
	return 0;
}
