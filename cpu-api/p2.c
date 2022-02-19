#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    FILE* fp = fopen("p2.txt", "w");
    fprintf(fp, "parent\n");
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0) {
        fprintf(fp, "child\n");
    }
    return 0;
}