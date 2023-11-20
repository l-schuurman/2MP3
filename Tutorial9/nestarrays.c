#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int a[5];
    int b[5][5];
    int c[5][5][5];
    int count;

    printf("\nint a[5]\n");

    count = 0;
    for (int i = 0; i < 5; i++) {
        count++;
        a[i] = count;
        printf("%p\n", &a[i]);
    }

    // printf("\nint b[5][5]\n");

    // count = 0;
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         count++;
    //         b[i][j] = count;
    //         printf("%p\n", &b[i][j]);
    //     }
    // }

    // printf("\n");

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         printf("%d ", b[i][j]);
    //     }
    // }

    // printf("\n");

    // int* d = &b[0][0];
    // for (int i = 0; i < 25; i++) {
    //     printf("%d ", d[i]);
    // }

    // printf("\n");

    // for (int i = 0; i < 25; i++) {
    //     printf("%d ", b[i / 5][i % 5]);
    // }

//     printf("\nint c[5][5][5]\n");
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             for (int k = 0; k < 5; k++) {
//                 printf("%p\tx = %d\ty = %d\tz = %d\n", &c[i][j][k], i, j, k);
//             }
//         }
//     }
}