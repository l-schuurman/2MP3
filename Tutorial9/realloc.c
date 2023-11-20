#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int* a = (int*)malloc(sizeof(int) * 12);

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    a[5] = 5;
    a[6] = 6;
    a[7] = 7;
    a[8] = 8;

    for (int i = 0; i <= 11; i++) {
        printf("%d ", a[i]);
    }

    // a = realloc(a, sizeof(int) * 2);

    // printf("\n");
    // for (int i = 0; i <= 11; i++) {
    //     printf("%d ", a[i]);
    // }

    // char* b = (char*)malloc(sizeof(char));
    // *b = 'a';

    // printf("\n");
    // for (int i = 0; i <= 11; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");

    // Debug prints:
    // printf("Address of a: %p\n", a);
    // printf("Address of b: %p\n", b);

    printf("%d\n", *(a + 8));
    printf("%p\n", (a + 8));
    printf("%c\n", *(a + 8));

    return 0;
}