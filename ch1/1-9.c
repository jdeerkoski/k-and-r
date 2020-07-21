#include <stdio.h>
#define FALSE 0
#define TRUE 1

int main () {
    int last_was_space, c;
    last_was_space = FALSE; 
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (last_was_space == FALSE) {
                putchar(c);
                last_was_space = TRUE;
            }
        } else {
            putchar(c);
            last_was_space = FALSE;
        }
    }
}