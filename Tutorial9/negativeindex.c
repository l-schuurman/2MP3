#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int modified;
    char buffer[64];

    modified = 0;

    printf("%p\n", buffer);
    // printf("%p\n", &buffer[0]);
    // printf("%p\n", &buffer[1]);
    // printf("%p\n", &buffer[2]);

    printf("%p\n", &modified);

    printf("%p\n", &buffer[-1]);
    printf("%p\n", &buffer[-3]);

    if (modified != 0) {
        printf("you have changed the 'modified' variable\n");
    } else {
        printf("Try again?\n");
    }

    printf("%d\n", modified);
}