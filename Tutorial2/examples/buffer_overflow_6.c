#include <stdio.h>
#include <string.h>

int main() {
    int num = 123;
    char buffer[4];
    int n = sprintf(buffer, "%d", num);
    printf("%s\t\t%ld\t%d\n", buffer, sizeof(buffer), n);
    // printf("%p\n", buffer);

    int num2 = 123456;
    char buffer2[4];
    int n2 = sprintf(buffer2, "%d", num2);
    printf("%s\t\t%ld\t%d\n", buffer2, sizeof(buffer2), n2);
    // printf("%p\n", buffer2);

    int num3 = 123456789;
    char buffer3[40];
    int n3 = sprintf(buffer3, "%d", num3);
    printf("%s\t%ld\t%d\n", buffer3, sizeof(buffer3), n3);
    // printf("%p\n", buffer3);

    // printf("%s\n", buffer);
    // printf("%s\n", buffer2);

    return 0;
}