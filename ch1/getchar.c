#include <stdio.h>

int main () {
    int c, result;
    result = (getchar() != EOF);
    printf("Result: %d\n", result);
    while (result == 1) {
        result = (getchar() != EOF);
        printf("Result: %d\n", result);
    }
}