#include <stdio.h>

int main () {
    long nb, nt, nn;
    int c;
    nb = nt = nn = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') nb++;
        if (c == '\t') nt++;
        if (c == '\n') nn++;
    }
    printf("Blanks: %ld\n", nb);
    printf("Tabs: %ld\n", nt);
    printf("Newlines: %ld\n", nn);
}