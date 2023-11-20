#include <stdio.h>
#include <string.h>

#define PASSWORD_FILE "mechtron"

int main() {
    char input[9];
    char password[9];

    sscanf(PASSWORD_FILE, "%s", password);

    printf("Enter password: ");
    scanf("%s", input);

    // Debug prints:
    // printf("Address of input: %p\n", (void*)&input);
    // printf("Address of password: %p\n", (void*)&password);
    // printf("Input: %s\n", input);
    // printf("Password: %s\n", password);

    if (strncmp(password, input, 9) == 0)
        printf("Granted\n");
    else
        printf("Denied\n");

    return 0;
}