#include <stdio.h>

int main() {
    int num = 123;
    char buffer[4];
    int n = sprintf(buffer, "%d", num);
    printf("%s\t%d\n", buffer, n);

    return 0;
}