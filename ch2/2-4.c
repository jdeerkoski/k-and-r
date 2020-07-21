#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

char *strchr(const char *str, int c);
// size_t getline (char **lineptr, size_t *n, FILE *stream);

char *squeeze(char s1[], char s2[])
{
   int i, j;
   size_t maxline = 1000;

   for (i=j=0; s1[i] != '\0'; i++) {
       // printf("i: %d s1[i]: %c  ", i, s1[i]);
       if (!strchr(s2, s1[i])) {
           // printf("including\n");
           s1[j++] = s1[i];
       } else {
           // printf("skipping\n");
       }
   } 
   s1[j] = '\0';
   return s1;
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

        printf("squeeze: %s\n", squeeze(s1, s2));
    }
}