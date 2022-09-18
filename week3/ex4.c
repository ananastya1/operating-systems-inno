#include <stdio.h>
#include <stdlib.h>


void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b) {
    int n = *((int *) b);
    int *nums = (int *) a;
    int *sum = calloc(1, sizeof(int));
    for (int i = 0; i < n + 1; i++) {
        *sum += nums[i];
    }
    return sum;
}

void* addDouble(const void* a, const void* b){
    int n = *((int*)b);
    double *nums = (double *)a;
    double *sum = calloc(1, sizeof(double));
    for (int i = 0; i < n+1; i++) {
        *sum += nums[i];
    }
    return sum;
}

void *mulInt(const void *a, const void *b) {
    int n = *((int *) b);
    int *nums = (int *) a;
    int *mul = &nums[0];
    for (int i = 0; i < n + 1; i++) {
        *mul = (*mul) * nums[i];
    }
    return mul;
}

void *mulDouble(const void *a, const void *b) {
    int n = *((int *) b);
    double *nums = (double *) a;
    double *mul = &nums[0];
    for (int i = 0; i < n + 1; i++) {
        *mul = (*mul) * nums[i];
    }
    return mul;
}

void *meanInt(const void *a, const void *b) {
    int n = *((int *) b);
    int *nums = (int *) a;
    int *sum = &nums[0];
    for (int i = 0; i < n + 1; i++) {
        *sum += nums[i];
    }
    *sum = (*sum) / n; 
    return sum;
}

void *meanDouble(const void *a, const void *b) {
    int n = *((int *) b);
    double *nums = (double *) a;
    double *sum = &nums[0];
    for (int i = 0; i < n + 1; i++) {
        *sum += nums[i];
    }
    *sum = (*sum) / n; 
    return sum;
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *)) {

    void *output;

    if (size == sizeof(int)) { // base is a pointer to an integer

        int *array = (int *) base;
        int ar[6];
        int *h = (int *) initial_value;
        ar[0] = *h;
        for (int i = 1; i < 6; i++) {
            ar[i] = array[i - 1];
        }
        output = opr(ar, &n);


    } else { // base is a pointer to a double

        double *array = (double *) base;
        double ard[6];
        double *hh = (double *) initial_value;
        ard[0] = *hh;
        for (int i = 1; i < 6; i++) {
            ard[i] = array[i - 1];
        }
        output = opr(ard, &n);

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
    free(doubles);
    


    return EXIT_SUCCESS;
}
