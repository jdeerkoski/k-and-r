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

int bitcount (unsigned x)
{
    int b=0;
    while (x>0) {
        x &= (x-1);
        b++;
            printf("x:          %s b: %d\n", printBinary(x), b);
    }
    return b;
}

int main (int argc, char *argv[]) {
    unsigned x;
    int y, z;

    x = atoi(argv[1]);
    y = x - 1;
    z = x & y;

    printf ("x: %d y: %d z: %d\n", x, y, z);
    printf("x:          %s\n", printBinary(x));
    printf("y:          %s\n", printBinary(y));
    printf("z:          %s\n", printBinary(z));

    printf("bitcount of x: %d\n", bitcount(x));
}