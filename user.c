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
int main(int argc,char**argv){
	printf(argc);
	return 0;
}