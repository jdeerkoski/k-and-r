#include <stdio.h>
#define OUT 0
#define IN 1
#define MAXLEN 20

int main () {
    int state, c, wordlen;
    int lencount[MAXLEN];

    for (int i=0; i<MAXLEN; i++) {
        lencount[i] = 0;
    }
    state = OUT; 
    wordlen = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                lencount[wordlen]++;
                state = OUT;
            }
        } else {
            if (state == OUT) {
                wordlen = 1;
                state = IN;
            } else {
                wordlen++;
            }
        }
    }

    for (int i=0; i<MAXLEN; i++) {
        printf("%2d ", i);
        for (int j=1; j<=lencount[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}