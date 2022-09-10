#include<stdio.h>

int tribonacci(int);

int main(int argc, char *argv[]) {
    int n;
    printf("with 4:  %d\n", tribonacci(4));
    printf("with 36:  %d\n", tribonacci(36));
    return 0;
}

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int tmp;
    int first = 0;
    int second = 1;
    int third = 1;
    for (int i = 0; i <= n - 3; ++i) {
        tmp = third;
        third = first + second + third;
        first = second;
        second = tmp;
    }
    return third;
}