#include <stdio.h>
#include <ctype.h>
#define MAXLEN 26

int main () {
    int c;
    int lencount[MAXLEN];

    for (int i=0; i<MAXLEN; i++) {
        lencount[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            printf("char: ");
            putchar(c);
            printf(" array: ");
            printf("%d", tolower(c) - 'a');
            putchar('\n');
            lencount[tolower(c) - 'a']++;            
        }
    }

    for (int i=0; i<MAXLEN; i++) {
        putchar('a' + i);
        printf(": ");
        for (int j=1; j<=lencount[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}