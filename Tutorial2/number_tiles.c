#include <stdio.h>


int bruteForce3DigitLoopStr();
int bruteForce3DigitLoop();
int bruteForce3DigitSingleLoop();
int bruteForceAllDigits();
int bruteForceAllDigitsCeiling();


int main() {


    printf("String Conversion (N^2)\t%d\n", bruteForce3DigitLoopStr());
    printf("Mathematical (N^2)\t%d\n", bruteForce3DigitLoop());
    printf("Mathematical (N)\t%d\n", bruteForce3DigitSingleLoop());
    printf("By Each Digit (N^6)\t%d\n", bruteForceAllDigits());
    printf("By Each Digit Ceiling (N^6)\t%d\n", bruteForceAllDigitsCeiling());
}


int bruteForce3DigitLoopStr() {
    char A, B, C, D, E, F;
    char ABC[4], DEF[4];
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i + j == 1234) {
                snprintf(ABC, 4, "%d", i);
                snprintf(DEF, 4, "%d", j);

                A = ABC[0];
                B = ABC[1];
                C = ABC[2];
                D = DEF[0];
                E = DEF[1];
                F = DEF[2];

                // printf("%d %d %d %d %d %d\n", A, B, C, D, E, F);
                if ((A > D) && (B > E) && (C > F)) {
                    // printf("%d %d\n", i, j);
                    count += 1;
                }
            }
        }
    }

    return count;
}


int bruteForce3DigitLoop() {
    int A, B, C, D, E, F;
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i + j == 1234) {
                A = i / 100;
                B = (i / 10) % 10;
                C = i % 10;
                D = j / 100;
                E = (j / 10) % 10;
                F = j % 10;
                // printf("%d %d %d %d %d %d\n", A, B, C, D, E, F);
                if ((A > D) && (B > E) && (C > F)) {
                    // printf("%d %d\n", i, j);
                    count += 1;
                }
            }
        }
    }

    return count;
}


int bruteForce3DigitSingleLoop() {
    int A, B, C, D, E, F;
    int count = 0;
    int j;
    for (int i = 0; i < 1000; i++) {
        j = 1234 - i;
        A = i / 100;
        B = (i / 10) % 10;
        C = i % 10;
        D = j / 100;
        E = (j / 10) % 10;
        F = j % 10;
        // printf("%d %d %d %d %d %d\n", A, B, C, D, E, F);
        if ((A > D) && (B > E) && (C > F)) {
            // printf("%d %d\n", i, j);
            count += 1;
        }
    }

    return count;
}


int bruteForceAllDigits() {
    int A, B, C, D, E, F;
    int count = 0;
    int count2 = 0;
    for (A = 0; A < 10; A++) {
        for (B = 0; B < 10; B++) {
            for (C = 0; C < 10; C++) {
                for (D = 0; D < 10; D++) {
                    for (E = 0; E < 10; E++) {
                        for (F = 0; F < 10; F++) {
                            count2 += 1;
                            if ((C + F) + 10*(B + E) + 100*(A + D) == 1234) {
                                if ((A > D) && (B > E) && (C > F)) {
                                    count += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", count2);

    return count;    
}


int bruteForceAllDigitsCeiling() {
    int A, B, C, D, E, F;
    int count = 0;
    int count2 = 0;
    for (A = 0; A < 10; A++) {
        for (B = 0; B < 10; B++) {
            for (C = 0; C < 10; C++) {
                for (D = 0; D < A; D++) {
                    for (E = 0; E < B; E++) {
                        for (F = 0; F < C; F++) {
                            count2 += 1;
                            if ((C + F) + 10*(B + E) + 100*(A + D) == 1234) {
                               // printf("%d%d%d %d%d%d\n", A, B, C, D, E, F);
                                count += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", count2);

    return count;    
}
