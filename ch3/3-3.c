#include <stdio.h>
#define MAX_CHARS 1000

void expand (char *s1, char *s2) {
    int i=0,j=0;

    while (s1[i] != '\0') {
        if (s1[i+1] == '-') {
            if (s1[i] >= 'a' && s1[i] <= 'z') {
                if ((s1[i+2] >= 'a') && (s1[i+2] <= 'z') && (s1[i] <= s1[i+2])) {
                    char c = s1[i];
                    while (c <= s1[i+2]) {
                        s2[j++] = (c++);
                    }
                    i=i+3;
                    continue;                
                }
            } else if (s1[i] >= 'A' && s1[i] <= 'Z') {
                if ((s1[i+2] >= 'A') && (s1[i+2] <= 'Z') && (s1[i] <= s1[i+2])) {
                    char c = s1[i];
                    while (c <= s1[i+2]) {
                        s2[j++] = (c++);
                    }
                    i=i+3;
                    continue;                
                }
            } else if (s1[i] >= '0' && s1[i] <= '9') {
                if ((s1[i+2] >= '0') && (s1[i+2] <= '9') && (s1[i] <= s1[i+2])) {
                    char c = s1[i];
                    while (c <= s1[i+2]) {
                        s2[j++] = (c++);
                    }
                    i=i+3;
                    continue;                
                }
            }
        }
        s2[j++] = s1[i++];
    }
    s2[j] = '\0';
}

int main(int argc, char *argv[]) {
    char s1[MAX_CHARS], s2[MAX_CHARS];
    int i, c;

    for (i=0; ((c = getchar()) != EOF); i++) {
        //printf("copying: %c\n", c);
        s1[i] = (char) c;
    }

    printf("original:\n%s\n", s1);

    expand (s1, s2);

    printf("result:\n%s\n", s2);
}