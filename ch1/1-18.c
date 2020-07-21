#include <stdio.h>
#define MAXLINE 1000
#define IN 0
#define OUT 1

int inputline(char line[], int maxline);
void copy(char to[], char from[]);

int inputline(char s[], int lim) {
    int c, i, j, b;
    char buff[MAXLINE];
    int state;
    
    state = OUT;
    i=0;

    while (i<lim-1 && (c=getchar())!=EOF && c!='\n') {
        /*printf("char: '");
        putchar(c);
        printf("'\n");*/
        if (c == '\t' || c == ' ') {
            if (state == IN) {
                //printf("-- continued blank. buffer the char.\n");
                b++;
                buff[b] = c;
            } else {
                //printf("-- new blank. buffer the char.\n");
                state = IN;
                b=0;
                buff[b] = c;
            }
        } else {
            if (state == IN) {
                //printf("-- end of blanks. add buffer then add the char.\n");
                for (j=0; j<=b; j++) {
                    s[i++] = buff[j];
                }
                s[i++] = c;
                b=0;
                state = OUT;
            } else {
                //printf("-- continued nonblank. add the char.\n");
                s[i++] = c;
            }
        }
/*
        printf("str: ");
        for (j=0; j<i; j++) {
            putchar(s[j]);
        }
        printf("!\n");*/
    }
    /*
    if (c == '\n' && (i < lim-1)) {
        s[i++] = c;
    }*/
    s[i] = '\0';

    return i;
}

int main() {
    int len;
    int max;
    char line[MAXLINE];

    max = 0;
    while ((len = inputline(line, MAXLINE)) > 0) {
        printf("%s***\n", line);
    }

    return 0;
}