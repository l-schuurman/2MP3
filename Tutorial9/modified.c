#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char * buffer = malloc(sizeof(char));
    int * modified = malloc(sizeof(int));

    *modified = 0;

    // printf("%p\n", buffer);
    // printf("%p\n", modified);

    scanf("%s", buffer);

    if (*modified != 0) {
        printf("you have changed the 'modified' variable\n");
    } else {
        printf("Try again?\n");
    }
}