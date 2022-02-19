#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int x;
    x = 50;
    printf("%d\n", x);
    x = fork();
    printf("%d\n", x);
    return 0;
}