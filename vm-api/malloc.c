#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int* ptr = malloc(sizeof(int) * 10);
    free(10);
    printf("%d", *ptr);
    return 0;
}