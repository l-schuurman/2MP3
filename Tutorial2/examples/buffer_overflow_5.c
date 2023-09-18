#include <stdio.h>
#include <string.h>

int main() {
    int num = 123;
    char buffer[3];
    int n = sprintf(buffer, "%d", num);
    printf("%s\t%p\n", buffer, &buffer);

    int num2 = 456;
    char buffer2[3];
    int n2 = sprintf(buffer2, "%d", num2);
    printf("%s\t%p\n", buffer2, &buffer2);

    // printf("%ld\n", sizeof(buffer));
    // printf("%ld\n", sizeof(buffer2));

    // printf("%ld\n", strlen(buffer));
    // printf("%ld\n", strlen(buffer2));

    // printf("%s\n", buffer);

    // char *str = buffer;
    // int i = 0;
    // while( str[i] ) {
    //     printf("%c", str[i]);
    //     i++;
    //     if (!str[i]) i++; 
    // }
    // printf("\n");

    return 0;
}