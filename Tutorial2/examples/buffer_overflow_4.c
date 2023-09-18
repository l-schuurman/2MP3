#include <stdio.h>
#include <string.h>

int main() {
    char gerald[6] = "Gerald";
    char hatch[5] = "Hatch";
    char centre[6] = "Centre";

    // printf("Allocated memory size:\t\t\t%ld\n", sizeof(gerald));
    // printf("String Length:\t\t\t\t%ld\n", strlen(gerald));
    printf("Memory Address of first character:\t%p\n", gerald);
    // printf("%s\n", gerald);

    // printf("Allocated memory size:\t\t\t%ld\n", sizeof(hatch));
    // printf("String Length:\t\t\t\t%ld\n", strlen(hatch));
    printf("Memory Address of first character:\t%p\n", hatch);
    // printf("%s\n", hatch);

    // printf("Allocated memory size:\t\t\t%ld\n", sizeof(centre));
    // printf("String Length:\t\t\t\t%ld\n", strlen(centre));
    printf("Memory Address of first character:\t%p\n", centre);
    // printf("%s\n", centre);

    int i = 0;
    char *str = hatch;

    while ( str[i] ) {
        printf("%c ", str[i]);
        i++;
    }

    return 0;
}