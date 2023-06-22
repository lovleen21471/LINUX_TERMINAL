#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
int main(int argc, char* argv[]){
	struct dirent *dq;
	DIR *dr = opendir(".");
	if(dr == NULL)
	{
		printf("Error");
		return 0;
	}
	char **s;
	int i = 0;
	if(argv[1] == "-r"){
		while((dq = readdir(dr))!= NULL){
			s[i] = dq->d_name;
			i++;
		}
		while(i >=0){
			printf("%s\t", s[i]);
			i--;
		}
	}	
	if(argv[1] == "-A")
	{	while((dq = readdir(dr))!= NULL){
			if(!strcmp(dq->d_name, ".") || !strcmp(dq->d_name, ".."))
				continue;
			printf("%s\t", dq->d_name);
		}
	}
	else
	{
		while((dq = readdir(dr))!= NULL){
			printf("%s\t", dq->d_name);
		}
	}
	closedir(dr);
	return 0;
}

