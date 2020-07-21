#include <stdio.h>
#define MAXLINE 1000

int inputline(char line[], int maxline);
void copy(char to[], char from[]);

int inputline(char s[], int lim) {
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i){
        if (i<lim-1) s[i] = c;
    }
    if (c == '\n' && (i < lim-1)) {
        s[i] = c;
        ++i;
    }
    if (i <= lim-1) {
       s[i] = '\0';
    } else {
        s[lim-1] = '\0';
    }
    return i;
}

int main() {
    int len;
    int max;
    char line[MAXLINE];

    max = 0;
    while ((len = inputline(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }

    return 0;
}