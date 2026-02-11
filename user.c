/**
user.c
This file will be executed by oss.c
This file should be compiled as a separated executable.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main(int argc,char**argv){
	pid_t pid = getpid();
	pid_t ppid = getppid();
	int iterations = atoi(argv[0]);
	int iter = 0;
	for (int i = 0; i < iterations; i++){
		iter = i + 1;
		printf("USER PID:%d\tPPID:%d Iteration:%d before sleeping.",pid,ppid,iter);
		sleep(1);
		printf("USER PID:%d\tPPID:%d Iteration:%d after sleeping.",pid,ppid,iter);
	}
		

	return EXIT_SUCCESS;
}