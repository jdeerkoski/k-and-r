#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

void reverse(char s[])
{
    int c, i, j;
    for (i=0, j=strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char * printBinary (int a) {
    char *b = (char *)malloc(1000 * sizeof(char));
    int i=0;
    int j;
    for (j=0; j<32; j++) {
        //printf("a: %d ", a);
        //b[i++] = '0' + (a % 2);
        
        int mask = (int) (pow((double) 2, (double) j));
        //printf("mask: %x\n", mask);
        //printf("a&mask: %x\n", (a & mask));
        b[i++] = '0' + (a & mask ? 1 : 0);

        //printf("b[i]: %c", b[i-1]);
        //a = a / 2;
        //printf("newa: %d\n", a);
    }
    b[i] = '\0';
    //printf("b: %s\n", b);
    reverse(b);
    return b;
}

void itob(int n, char s[], int b)
{
    int i, sign;

    i=0;
    if (n == INT_MIN) {
        printf("in special section for INT_MIN\n");
        do {
            int r = -(n%b);
            if (r < 10) {
                s[i++] = r + '0';
            } else {
                s[i++] = (r-10) + 'a';
            }
        } while ((n/=b) < 0);
        s[i++] = '-';
        s[i] = '\0';
        reverse(s);
        return;
    }
    if ((sign = n) < 0)
        n = -n;
    do {
        int r = n%b;
        if (r < 10) {
            s[i++] = r + '0';
        } else {
            s[i++] = (r-10) + 'a';
        }
    } while ((n/=b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main (int argc, char *argv[]) {
    int x;
    char s[1000];

    x = INT_MIN;
    itob(x,s, 12);
    printf("%s\n", printBinary(x));
    printf("%s\n", printBinary(-x));
    printf("%d %s %x\n", x, s, x);

    x = INT_MAX;
    itob(x,s, 12);
    printf("%s\n", printBinary(x));
    printf("%d %s %x\n", x, s, x);

    x = 23632;
    itob(x,s, 12);
    printf("%s\n", printBinary(x));
    printf("%d %s %x\n", x, s, x);

    x = -23632;
    itob(x,s, 12);
    printf("%s\n", printBinary(x));
    printf("%s\n", printBinary(-x));
    printf("%d %s %x\n", x, s, x);
}