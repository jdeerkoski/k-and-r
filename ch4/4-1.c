#include <stdio.h>
#include <string.h>

int strrindex (char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s)-1; s[i] != '\0'; i--) {
        printf("i: %d\n", i);
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strindex (char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        printf("i: %d\n", i);
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int main (int argc, char * argv[])
{
    char *a, *b;

    a = "stesyrafgdsadfsatr";
    b = "ad";    
    printf("a: %s b: %s strindex: %d\n",a, b, strindex(a, b));
    printf("a: %s b: %s strrindex: %d\n",a, b, strrindex(a, b));
}