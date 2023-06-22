#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
int main(int argc, char* argv[]){
	if(!strcmp(argv[1], "-n")){
		FILE *fr;
		fr = fopen(argv[2], "r");
		char c;
		int l = 1;
		int q = 0;
		while((c = fgetc(fr))!= EOF){
			if(q == 0){
				printf("\t%d", l);
				l++;
				q = 1;
			}
			printf("%c", c);
			if(c == '\n'){
				printf("\t%d ", l);
				l++;
			}
		}
		}
	if(!strcmp(argv[1] , "-u")){
		FILE *fr;
		fr = fopen(argv[2], "r");
		char c;
		while((c = fgetc(fr))!= EOF){
			printf("%c", c);
		}
	}
	else{
		FILE *fr;
		fr = fopen(argv[1], "r");
		char c;
		while((c = fgetc(fr))!= EOF){
			printf("%c", c);
		}
	}
	return 0;
}
