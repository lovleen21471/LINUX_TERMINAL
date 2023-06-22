#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
void ec(char* arg[]){
	int q = 0;
	if(!strcmp(arg[1], "-n")){
		int i = 2;
		while(arg[i] != NULL){
			printf("%s ", arg[i]);
			i++;
		}
		q = 1;
	}
	if(!strcmp(arg[1], "-E")){
		int i = 2;
		while(arg[i] != NULL){
			printf("%s ", arg[i]);
			i++;
		}
		printf("\n");
		q = 1;
	}
	if(q == 0){
		int i = 1;
		while(arg[i] != NULL){
			printf("%s ", arg[i]);
			i++;

		}
		printf("\n");
	}
	return;
}
void pd(int argc, char argv[]){
	char pathway[110000];
	if(argv[4] == '-' && argv[5] == 'P'){
		printf("%s ", getcwd(pathway, sizeof(pathway)));
	}
	if(argv[4] == '-' && argv[5] == 'L'){
		printf("%s", getcwd(pathway, sizeof(pathway)));
	}
	else{
		printf("%s ", getcwd(pathway, sizeof(pathway)));
	}
	return;
}
void cd(char* arg[]){
	if(!strcmp(arg[1], "-P")){
		int res = chdir(arg[2]);
		if(res == 0){
			return;
		}
		else{
			printf("Error");
		}
	}
	else{
		int res = chdir(arg[1]);
		printf("%d", res);
		if(res == 0){
			return;
		}
		else{
			printf("Error:");
		}
	}
	return;
}	
int main(){
	char pathway[110000];
	int p = 0;
	while( p == 0){
		printf("%s$", getcwd(pathway, sizeof(pathway)));
		char inpt[10000];
		if(fgets(inpt, 10000, stdin));
		inpt[strlen(inpt)-1] = '\0';

		if(!(strcmp(inpt, ""))){
			continue;
		}
		const char tokens[2] = " ";
		int argc = 1;
		for(int i =0; i < strlen(inpt);i++){
			if(inpt[i] == ' ') argc++;
		}
		char ** argv = (char**)malloc((argc+1)* sizeof(char*));
		char *token = strtok(inpt, tokens);
		for(int i =0; token != NULL; i++){
			argv[i] = token;
			token = strtok(NULL, tokens);
		}
		argv[argc] = NULL;
		if(inpt[0] == 'e' && inpt[1] == 'x' && inpt[2] == 'i' && inpt[3] == 't'){
			p = 1;
 			printf("exitted succeffully");
			exit(EXIT_FAILURE);
			break;
		}
		if(inpt[0] == 'p' && inpt[1] == 'w' && inpt[2] == 'd'){
			pd(strlen(inpt), inpt);
			continue;
		}
		if(!strcmp(argv[0], "echo")){
			ec(argv);
			continue;
		}
		if(!strcmp(argv[0], "cd")){
			cd(argv);
			continue;
		}
		else{
			int id = fork();
			int status;
			if(id < 0){
				printf("Failed to fork()");
				return 0;
			}
			if(id == 0){
				if(!strcmp(argv[0], "date")){
					execv("/home/abc/date", argv);
					return 0;
				}
				if(!strcmp(argv[0], "mkdir")){
					execv("/home/abc/mkdir", argv);
					return 0;
				}
				if(!strcmp(argv[0], "rm")){
					execv("/home/abc/rm", argv);
					return 0;
				}
				if(!strcmp(argv[0], "ls")){
					execv("/home/abc/ls",argv);
					return 0;
				}
				if(!strcmp(argv[0], "cat")){
					execv("/home/abc/cat", argv);
					return 0;
				}
				else{
					printf("Enter a valid input");
					return 0;
				}
			
			}
			else{
				wait(NULL);
			}
		}
	} 
	return 0;
}
