#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char* arr = malloc(1024 * 1024 * atoi(argv[0]));
    if (arr == NULL) {
        printf("memory allocation error");
        exit(1);
    }
    for (;;) {
        int x = 0;
        arr[1] = x;
    }
    return 0;
}