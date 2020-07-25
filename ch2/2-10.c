#include <stdio.h>

int lower (int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

char *lowerstr (char * s) {
    int i;
    for (i=0; s[i] != '\0'; i++) {
        s[i] = lower(s[i]);
    }
    return s;
}

int main(int argc, char *argv[])
{
    char *s = argv[1];
    printf("lower: %s\n", lowerstr(s));
}