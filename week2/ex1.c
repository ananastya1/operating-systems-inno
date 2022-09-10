#include <stdio.h>
#include <float.h>
#include <limits.h>
int main(int argc, char *argv[]) {
    int a = INT_MAX;
    unsigned short int b = USHRT_MAX;
    signed long int c = LONG_MAX;
    float d = FLT_MAX;
    double e = DBL_MAX;
    printf("size: %d, value: %d\n", (int)(sizeof(a)), a);
    printf("size: %d, value: %d\n", (int)(sizeof(b)), b);
    printf("size: %d, value: %ld\n", (int)(sizeof(c)), c);
    printf("size: %d, value: %f\n", (int)(sizeof(d)), d);
    printf("size: %d, value: %lf\n", (int)(sizeof(e)), e);
    return 0;
}