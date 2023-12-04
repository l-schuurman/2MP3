#include <stdio.h>

struct AAAAAAAAAAAAAAAAAAAA {
    int a;
    int bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb;
    char *cccccccccccccccccc;
};

struct AAAAAAAAAAAAAAAAAAAA test[3] = {
    {56,    23, "hello"},
    {-1, 93463, "world"},
    { 7,     5,    "!!"}
};

int addOne(int num) {
    return ++num;
}

void functionWithArguments(char argument1, int argument2, double argument3, char *argument4) {
}

int main() {
    int increment = addOne(2);

    int count = 0;
    for (int i = 0; i < 10; i++)
        count++;

    printf("%d\n", increment);
}
