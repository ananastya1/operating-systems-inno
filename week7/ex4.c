#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc_(void *ptr, size_t new) {
    void *arr = malloc(new); 
    size_t old = 0;
    if (ptr != NULL) {
        old = malloc_usable_size(ptr);
    }
    if (new < old) {
        memcpy(arr, ptr, new);
    } else {
        memcpy(arr, ptr, old);
    }
    free(ptr);
    return arr;
}

