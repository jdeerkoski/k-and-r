#include <limits.h>
#include <stdio.h>
#define TEST 1+2+3

int slen (char s[]) {
    int i;
    i=0;
    while (s[i] != '\x0') {
        ++i;
    }
    return i;
}

int main() 
{
    enum months {JAN, FEB, MAR};
    char t[] = "xxxxxx";
    printf("%d\n", FEB);
    printf("%d %d %d\n", slen("hey"), 'x', t[0]);
    printf("Test %d\n", TEST);
   printf("Maximum bits in a byte %d\n", CHAR_BIT);

   printf("Minimum value for signed char %d\n", SCHAR_MIN);
   printf("Maximum value for signed char %d\n", SCHAR_MAX);
   printf("Maximum value for unsigned char %d\n", UCHAR_MAX);

   printf("Minimum value for char %d\n", CHAR_MIN);
   printf("Maximum value for char %d\n", CHAR_MAX);

   printf("Maximum bytes in multi-byte array %d\n", MB_LEN_MAX);

   printf("Minimum value of short int %d\n", SHRT_MIN);
   printf("Maximum value of short int %d\n", SHRT_MAX);
   printf("Maximum value of unsigned short int %d\n", USHRT_MAX);

   printf("Minimum value of int %d\n", INT_MIN);
   printf("Maximum value of int %d\n", INT_MAX);
   printf("Maximum value of unsigned int %d\n", UINT_MAX);


   printf("Minimum value of long int %ld\n", LONG_MIN);
   printf("Maximum value of long int %ld\n", LONG_MAX);

   return(0);
}