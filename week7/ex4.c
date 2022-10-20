#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc_(void *ptr, size_t new, size_t old) {
    void *arr = malloc(new); 
    if (new < old) {
        memcpy(arr, ptr, new);
    } else {
        memcpy(arr, ptr, old);
    }
    free(ptr);
    return arr;
}

