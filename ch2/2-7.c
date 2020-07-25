#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

size_t strlen (const char *s);

char * strrev (char * c) {
    int i;
    size_t size = strlen(c);
    char *b = (char *)malloc(size * sizeof(char));
    for (i = 0; i < size; i++) {
        b[size-i-1] = c[i];
    }
    b[size] = '\0';
    return b;
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
    b = strrev(b);
    return b;
}

int main (int argc, char *argv[]) {
    //int c;
    unsigned x;
    int n, p, y;
    //sizet maxline = 1000;

    //x = (char *)malloc(maxline * sizeof(char));

    x = atoi(argv[1]);
    p = atoi(argv[2]);
    n = atoi(argv[3]);

    printf ("x: %d p: %d n: %d\n", x, p, n);
    printf("x:          %s\n", printBinary(x));

    unsigned left = ((x >> (p+1)) << (p+1));    
    printf("left:       %s\n", printBinary(left));

    int right_shift = p + 1 - n;
    printf("right_shift: %x\n", right_shift);
    unsigned right_mask = ~(~0 << right_shift);
    printf("right_mask: %s\n", printBinary(right_mask));
    unsigned right = x & right_mask;
    printf("right:      %s\n", printBinary(right));

    unsigned mid_mask = (~(~0 << n))<< (p+1-n);
    printf("mid_mask:   %s\n", printBinary(mid_mask));
    unsigned mid = (~x) & mid_mask;
    printf("mid:        %s\n", printBinary(mid));

    int combined = left | mid | right;
    printf("c:          %s\n", printBinary(combined));
    printf("result: %d\n", combined);

}