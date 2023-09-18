#include <stdio.h>
#include <string.h>

int main() {
    char b[20] = "Hatch";

    printf("%s\n", b);
    printf("%ld\n", sizeof(b));
    printf("%ld\n", strlen(b));

    return 0;
}