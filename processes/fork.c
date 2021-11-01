#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    printf("Hello World, (PID:%d)\n",(int) getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed.\n");
        exit(1);
    } 
    else if (rc == 0) {
        printf("this is child process, (PID:%d)\n", (int) getpid());
    }
    else {
        printf("this is parent process, (PID:%d)\n", (int) getpid());
    }
}