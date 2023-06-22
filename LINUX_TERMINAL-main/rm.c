#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>	
int main(int argc, char* argv[]){
	printf("%d %c %c",argc, argv[0], argv[1]);
	if(!strcmp(argv[1], "-i")){
		printf("Do you want to delete the file Y/N:");
		char a;
		scanf("%c", &a);
		if(a == 'Y'){
			int t = unlink(argv[2]);
			
		}
		if(a == 'N'){
		}
		else{
		printf("Not valid input");
		}
	}
	if(!strcmp(argv[1], "-v")){
		int t = unlink(argv[1]);
		if(!t){
			printf("Enter a valid input\n");
		}
		else{
			printf("Removed");
		}
	} 
	else{
		int t = unlink(argv[1]);
		if(!t){
			printf("Enter a valid input\n");
		
		}
		else{
			printf("Removed successfully");
		}		
	}
	return 0;
}

