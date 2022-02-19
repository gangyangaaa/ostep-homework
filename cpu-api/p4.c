#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    printf("pid: %d\n", rc);
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        char *myargs[2];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = NULL;
        int err = execvp(myargs[0], myargs);
        if (err == -1) {
            fprintf(stderr, "exec failed\n");
            exit(1);
        }
    }
    else {
        //int rc_wait = wait(NULL);
        //printf("%d", rc_wait);
        int parent_wait = waitpid(rc, NULL, 0);
        if (parent_wait == -1) {
            printf("wait error");
            exit(1);
        }
        printf("parent: %d\n", parent_wait);
    }
    return 0;
}