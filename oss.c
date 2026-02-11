/**
Commands: oss [-h] [-n proc] [-s simul] [-t iter]
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>
void help(){
	printf("Usage: \n\toss [-h] [-n proc] [-s simult] [-t iter] \n");
	printf("-h: prints help message");
	printf("-n proc: Specifies the number of total children processes to launch.\n ");
	printf("-s simult: Specifies how many children processes are allowed to run simultaneously\n ");
	printf("-t iter: Specifies the number to pass to the user process.\n ");
}
int main(int argc,char**argv){
	int option = -1;
	int n = -1;
	int simul = -1;
  char *iter;
	int total = 0;

	//Get option arguments
	while ((option = getopt( argc,argv, "hnst"))!=1){
		switch(option){
			case 'h':
				help();
				break;
			case 's':
				simul = atoi(optarg);
				break;
			case 'n':
				n =  atoi(optarg);
				break;
			case 't':
				iter =  optarg;
				break;
			case '?':
				printf("unknown option. %c\n", option);
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
		int c = 0;
		pid_t pid; 
		char *cmd[] = {"./user", iter, NULL};
		while (c < simul){
			//launch new child process
			pid = fork();
      
			if (pid == 0){
				//run user.o
				int state = execvp(cmd[0],cmd);
				if (state == EXIT_SUCCESS){
					printf("OSS: [PID: %d] Success.\n", pid);
					exit(EXIT_SUCCESS);
				}else{
					printf("OSS: [PID: %d] Failure.\n", pid);
					exit(EXIT_FAILURE);
				}

				
			} else if (pid > 0){
				
			} else {
				perror("fork failed");
				exit(EXIT_FAILURE);
			}

			//oss outputs message of new child launched
			c++;
			total++;
		}
		while (total < n){
			int status;
			wait(&status);
			if (WIFEXITED(status)) {
				printf("Child exited with status: %d\n", WEXITSTATUS(status));
			}
			//launch new child process
			pid = fork();
			int state = execvp(cmd[0],cmd);
			if (state == EXIT_SUCCESS){
				printf("OSS: [PID: %d] Success.\n", pid);
				exit(EXIT_SUCCESS);
			}else{
				printf("OSS: [PID: %d] Failure.\n", pid);
				exit(EXIT_SUCCESS);
			}
			total++;
		}
		wait(NULL);
	}
	
	return 0;
}
