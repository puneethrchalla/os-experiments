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
        int rc_wait = wait(NULL);
        printf("this is parent of %d, (rc_wait:%d) (PID:%d)\n", rc, rc_wait, (int) getpid());
    }
}