#include <stdio.h>
#include <stdlib.h>

int N;

int main() {
    printf("Enter array size: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}