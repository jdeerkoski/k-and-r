#include <stdio.h>
#define OUT 0
#define IN 1

int main () {
    int state, c;
    state = OUT; 
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar(c);
            if (state == OUT) {
                state = IN;
            }
        }
    }
}