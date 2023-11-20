#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
    char* a = "hello";
    char* b = "hello";

    char c[6] = "hello";
    
    char* d = malloc(sizeof(char) * 6);
    strcpy(d, "hello");

    // printf("%p\n", a);
    // printf("%p\n", b);

    // printf("%p\n", &a[0]);
    // printf("%p\n", &b[0]);

    // printf("%p\n", c);
    // printf("%p\n", d);

    if(a == b) printf("a == b\n");
    // if(a == c) printf("a == c\n");
    // if(a == d) printf("a == d\n");

    // if(!strcmp(a, b)) printf("strcmp(a, b)\n");
    // if(!strcmp(a, c)) printf("strcmp(a, c)\n");
    // if(!strcmp(a, d)) printf("strcmp(a, d)\n");
}