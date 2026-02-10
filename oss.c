/**
Commands: oss [-h] [-n proc] [-s simul] [-t iter]
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

void help(){
	printf("oss [-h] [-n proc] [-s simult] [-t iter] \n");
	printf("-h: ");
	printf("-n proc: Specifies the number of total children processes to launch.\n ");
	printf("-s simult: Specifies how many children processes are allowed to run simultaneously\n ");
	printf("-t iter: Specifies the number to pass to the user process.\n ");
}
int main(int argc,char**argv){
	int option =-1;
	int n = -1;
	int simul = -1;
	int iter = -1;
	int total = 0;
	
	//Get option arguments
	while ((option = getopt( argc,argv, "hnst"))!=1){
		switch(option){
			case 'h':
				help();
				break;
			case 's':
				simul = (int) optarg;
				break;
			case 'n':
				n =  optarg;
				break;
				
			case 't':
				iter = optarg;
				break;
			case '?':
				if (optopt == 'f') {
					printf("Option: %c\n", option);
					fprintf(stderr, "requires [FileName] argument: -f\n");
				} else {
					printf(stderr, "unknown option. %c\n", option);
				}
				break;
		}
		
	}
	//check input
	if (n < 0){
		printf("Missing value (-n [number])");
	
	}else if (simul < 0){
		printf("Missing value (-s [number])");	
	}else if (iter < 0){
			printf("Missing integer value (-t [number])");
	}else{
		
	}
	
	return 0;
}