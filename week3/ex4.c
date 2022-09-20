#include <stdio.h>
#include <stdlib.h>


void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b) {
    int *first = (int *) a;
    int *second = (int *) b;
    int sum = *first + *second;
    int *p = &sum;
    return p;
}

void* addDouble(const void* a, const void* b){
    double *first = (double *) a;
    double *second = (double *) b;
    double sum = *first + *second;
    double *p = &sum;
    return p;
}

void *mulInt(const void *a, const void *b) {
    int *first = (int *) a;
    int *second = (int *) b;
    int sum = *first * *second;
    int *p = &sum;
    return p;
}

void *mulDouble(const void *a, const void *b) {
    double *first = (double *) a;
    double *second = (double *) b;
    double sum = *first * *second;
    double *p = &sum;
    return p;
}

void *meanInt(const void *a, const void *b) {
    int *first = (int *) a;
    int *second = (int *) b;
    int sum = *first + *second;
    int *p = &sum;
    return p;
}

void *meanDouble(const void *a, const void *b) {
    double *first = (double *) a;
    double *second = (double *) b;
    double sum = *first + *second;
    double *p = &sum;
    return p;
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *)) {

    void *output;

    if (size == sizeof(int)) { // base is a pointer to an integer

        int *array = (int *) base;
        int *h = (int *) initial_value;
        for (int i = 0; i < 5; i++) {
            h = opr(h, &array[i]);
        }
        if (opr==meanInt){
            int r = (*h) / n;
            h = &r;
        }
        output = (void *) h;
    }


     else { // base is a pointer to a double

        double *array = (double *) base;
        double *h = (double *) initial_value;
        for (int i = 0; i < 5; i++) {
            h = opr(h, &array[i]);
        }
        if (opr==meanDouble){
            double res = (*h) / n;
            h = (double *) &res;
        }
        output = (void *) h;
    }

    return output;
}


int main() {

    int *ints = (int*)malloc(sizeof(int) * 5);
    double *doubles = (double*)malloc(sizeof(double) * 5);

    for (int i = 0; i < 5; i++) {
        ints[i] = i+1;
        doubles[i] = i+1;
    }

    // Addition

    int *result1a;
    int zero = 0;
    double zerod = 0;

    result1a = (int *)aggregate(ints, sizeof(int), 5, &zero, addInt);

    printf("%d\n", *result1a);

    double *result2a;

    result2a = (double*)aggregate(doubles, sizeof(double), 5, &zerod, addDouble);

    printf("%f\n", *result2a);


    // Multiplication

    int *result1m;
    int one = 1;
    double oned = 1;

    result1m = (int *)aggregate(ints, sizeof(int), 5, &one, mulInt);

    printf("%d\n", *result1m);

    double *result2m;

    result2m = (double *)aggregate(doubles, sizeof(double), 5, &oned, mulDouble);

    printf("%f\n", *result2m);



    // Mean

    int *result1mean;

    result1mean = (int *)aggregate(ints, sizeof(int), 5, &zero, meanInt);

    printf("%d\n", *result1mean);

    double *result2mean;

    result2mean = (double *)aggregate(doubles, sizeof(double), 5, &zerod, meanDouble);

    printf("%f\n", *result2mean);


    // free the pointers
    free(ints);
 //   free(doubles);
    


    return EXIT_SUCCESS;
}
