#include <stdio.h>
#include <math.h>
#define MAXLINE 1000

int inputline(char line[], int maxline);

int inputline(char s[], int lim) {
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i){
        s[i]=c;
    }
    s[i] = '\0';
    return i;
}

int htoi (char h[]);

int htoi (char h[])
{
    int c=0, i=0, v=0;
    if (h[0] == '0') {
        if (h[1] == 'x' || h[1] == 'X') {
            c=2;
        }
    }

    while (h[c] != '\0') {
        //printf("loop on c=%d\n", c);
        if (h[c] >= 'a' && h[c] <= 'f') {
            v=10+(h[c] - 'a');
        }
        else if (h[c] >= 'A' && h[c] <= 'F') {
            v=10+(h[c] - 'A');
        }
        else if (h[c] >= '0' && h[c] <= '9') {
            v=h[c] - '0';
        } else {
            v=-1;
        }
        //printf("v=%d ", v);
        if (v>=0) {
            i = i * 16 + v;
            //printf("now i=%d \n", i);
        }
        c++;
    }

    return i;
}

int main()
{
    int len, i;
    char h[MAXLINE];
    while ((len = inputline(h, MAXLINE)) > 0) {
        i = htoi(h);
        printf("%d\n", i);
    }
}