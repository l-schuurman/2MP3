#include <stdio.h>
#include <string.h>

int main() {
    char * str = "I LOVE MECHATRONICS";
    int n = snprintf(NULL, 0, "%s", str);
    char buffer[n + 1];
    snprintf(buffer, n + 1, "%s", str);

    printf("%s\t\t%ld\t%d\n", buffer, sizeof(buffer), n);
    // printf("%p\n", buffer);

    return 0;
}