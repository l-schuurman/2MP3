#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int *a = (int *)malloc(sizeof(int));
    *a = 305419896;

    printf("%X\n", *a);

    char *b = (char *)a;
    printf("%X\t%X\t%X\t%X\n", b[0], b[1], b[2], b[3]);
}