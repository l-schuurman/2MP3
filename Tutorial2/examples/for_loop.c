#include <stdio.h>

int main() {
    printf("for(int i = 0; i < 10; i++)\n");
    for(int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    printf("\n");
    printf("for(int i = 0; i <= 9; i++)\n");
    for(int i = 0; i <= 9; i++) {
        printf("%d\n", i);
    }
    return 0;
}