#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int* a = malloc(sizeof(int));
    char* b = (char *)a;

    b[0] = 'a';

    printf("%d\t%d\n", *a, *b);


    return 0;
}