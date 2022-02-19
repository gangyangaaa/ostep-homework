#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd[2];
    int pip_err = pipe(fd);
    if (pip_err == -1) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    int rc_a = fork();
    if (rc_a < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc_a == 0) {
        //redirect stdout to fd[1]
        close(fd[0]);
        close(STDOUT_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        printf("First child says hello.");
    }
    else {
        int rc_b = fork();
        if (rc_b < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (rc_b == 0) {
            close(fd[1]);
            close(STDIN_FILENO);
            //reditect standinput to fd[0]
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            char buf[BUFSIZ];
            read(STDIN_FILENO, buf, BUFSIZ);
            printf("Second child print: %s\n", buf);
        }
        else {
            wait(NULL);
        }
    }
    return 0;
}