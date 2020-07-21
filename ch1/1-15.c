#include <stdio.h>

float fahrToCelsius (float fahr) {
    int celsius;
    celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
}

int main () {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("fahr   celsius\n");
    printf("----   -------\n");
    for (fahr=upper; fahr>=lower; fahr=fahr-step) {
        celsius = fahrToCelsius(fahr);
        printf(" %3.0f\t%6.1f\n", fahr, celsius);
    }
}