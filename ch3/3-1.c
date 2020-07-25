#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE 1000000000

//int v[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
long a[ARRAY_SIZE];

long binsearch(long x, long v[], long n)
{
    long low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        //printf("x: %d low: %d high: %d\n", x, low, high);
        mid = (low+high) / 2;
        //printf("mid: %d v[mid]: %d\n", mid, v[mid]);
        if (x < v[mid]) {
            //printf("decreasing high to: %d\n", mid-1);
            high = mid - 1;
        } else if (x > v[mid]) {
            //printf("increasing low to: %d\n", mid+1);
            low = mid + 1;
        } else {
            //printf("match, returning mid\n");
            return mid;
        }   
    }
    return -1;
}

long binsearch2(long x, long v[], long n)
{
    long low, high, mid;
    low = 0;
    int trials = 0;
    high = n - 1;
    mid = (low+high) / 2;
    trials++;
    //printf("x: %d low: %d high: %d mid: %d v[mid]: %d\n", x, low, high, mid, v[mid]);
    while ((low <= high) && (x != v[mid])) {
        if (x < v[mid]) {
            //printf("decreasing high to: %d\n", mid-1);
            high = mid - 1;
        } else {
            //printf("increasing low to: %d\n", mid+1);
            low = mid + 1;
        }  
        mid = (low+high) / 2;
        trials++;
        //printf("x: %d low: %d high: %d mid: %d v[mid]: %d\n", x, low, high, mid, v[mid]);
    }
    //printf("x: %d low: %d high: %d mid: %d v[mid]: %d\n", x, low, high, mid, v[mid]);
    printf("trials: %d\n", trials);
    if (x == v[mid]) return mid;
    return -1;
}

int main (int argc, char *argv[]) {
    int x = atoi(argv[1]);
    long size;
    long result;
    long i;
    clock_t start, end;
    double cpu_time_used;

    printf("starting init loop\n");
    start = clock();
    a[0] = 0;
    a[1] = 2;
    printf("starting init loop\n");
    for (i=2; i<ARRAY_SIZE; i++) {
        a[i] = a[i-1] + 2;
        //printf ("%d %f\n", i, a[i]);
    }
    printf("ending init loop\n");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf ("start    : %.40f\n", start);
    printf ("end      : %.40f\n", end);
    printf ("time used: %.40f\n", cpu_time_used);
    size = sizeof a / sizeof a[0];
    printf ("size:  %d\n", size);

    printf ("a[7817]:  %d\n", a[7817]);
    printf ("a[9655]:  %d\n", a[9655]);
    printf ("a[999999999]:  %d\n", a[999999999]);

    start = clock();
    result = binsearch(x, a, size);
    end = clock();
    cpu_time_used = ((double) (end - start));

    printf ("search result:  %d\n", result);
    printf ("start    : %.40f\n", start);
    printf ("end      : %.40f\n", end);
    printf ("time used: %.40f\n", cpu_time_used);

    start = clock();
    result = binsearch2(x, a, size);
    end = clock();
    cpu_time_used = ((double) (end - start));

    printf ("search result2: %d\n", result);
    printf ("start    : %.100f\n", start);
    printf ("end      : %.100f\n", end);
    printf ("time used: %.100f\n", cpu_time_used);
}
