#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

char *strchr(const char *str, int c);
// size_t getline (char **lineptr, size_t *n, FILE *stream);

int any(char s1[], char s2[])
{
   int i;

   for (i=0; s1[i] != '\0'; i++) {
       // printf("i: %d s1[i]: %c  ", i, s1[i]);
       if (s1[i] != '\n' && strchr(s2, s1[i])) {
           // printf("including\n");
            return i;
           // printf("skipping\n");
       }
   }
   return -1;
}

int main()
{
    int len, i;
    size_t maxline = 1000;
    char *s1, *s2;

    s1 = (char *)malloc(maxline * sizeof(char));
    s2 = (char *)malloc(maxline * sizeof(char));
    if( s1 == NULL || s2 == NULL )
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    
    while (TRUE) {
        printf("s1: ");
        getline(&s1, &maxline, stdin);
        // printf("s1: %s", s1);
        printf("s2: ");
        getline(&s2, &maxline, stdin);
        // printf("s2: %s", s2);

        printf("any: %d\n", any(s1, s2));
    }
}