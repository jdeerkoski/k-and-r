#include <stdio.h>
#define MAXLINE 1000

int inputline(char line[], int maxline);
void reverse(char to[], char from[], int len);

int inputline(char s[], int lim) {
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i){
        s[i]=c;
    }
    s[i] = '\0';
    return i;
}

void reverse (char to[], char from[], int len) {
    int i, j;
    j=0;
    for (i=len-1; i>=0; i--) {
        //printf("copying %d to array\n", from[i]);
        to[j++] = from[i];        
    }
    //printf("copied %d chars\n", j);
    to[j] = '\0';
}

int main() {
    int len;
    int max;
    char line[MAXLINE], revline[MAXLINE];

    max = 0;
    while ((len = inputline(line, MAXLINE)) > 0) {
        //printf("line: %s\n", line);
        //printf("line len: %d\n", len);
        reverse(revline, line, len);
        printf("%s\n", revline);
    }

    return 0;
}