#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("hello\n");
    }
    else {
        int rc_wait = wait(NULL);
        printf("hello_parent\n");
    }
    return 0;
}