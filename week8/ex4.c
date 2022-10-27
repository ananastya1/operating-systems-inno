#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

int main() {
    void *ptr[10];
    struct rusage info;
    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(10485760);
        memset(ptr[i], 0, 10485760);
        sleep(1);
        getrusage(RUSAGE_SELF, &info);
        printf("%s: %ld\n", "memory used: ", info.ru_maxrss);
    }
  
    return 0;
}