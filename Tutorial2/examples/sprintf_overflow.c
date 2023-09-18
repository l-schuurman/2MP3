#include <stdio.h>
#include <string.h>

int main() {
    char * str = "I LOVE MECHATRONICS";
    char buffer[12];
    int n = sprintf(buffer, "%s", str);
    printf("%s\t\t%ld\t%d\n", buffer, sizeof(buffer), n);
    // printf("%p\n", buffer);

    return 0;
}