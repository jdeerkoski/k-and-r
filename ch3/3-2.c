#include <stdio.h>
#define MAX_CHARS 1000

void unescape(char *s, char *t) {
    int i=0, j=0, c;
    while ((c = t[i]) != '\0') {
        switch (c) {
            case '\\':
                if (t[i+1] == 'n') {
                    s[j++] = '\n';
                    i++;
                } else if (t[i+1] =='t') {
                    s[j++] = '\t';
                    i++;
                } else {
                    s[j++] = c;
                }
                break;
            default:
                s[j++] = c;
        }
        i++;
    }
    s[j] = '\0';
}

void escape(char *s, char *t) {
    int i=0, j=0, c;
    while ((c = t[i]) != '\0') {
        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
        }
        i++;
    }
    s[j] = '\0';
}

int main(int argc, char *argv[]) {
    char s[MAX_CHARS], t[MAX_CHARS];
    int i, c;

    for (i=0; ((c = getchar()) != EOF); i++) {
        //printf("copying: %c\n", c);
        t[i] = (char) c;
    }
    
    unescape (s, t);

    printf("result:\n%s\n", s);
}