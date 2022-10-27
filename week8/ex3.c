#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    void *ptr[10];
    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(10485760);
        memset(ptr[i], 0, 10485760);
        sleep(1);
    }
    // When ex2 is running in background, it appears in the process list and amount of used memory and swaps is increasing.
    // After end of execution, the process disappears from the list and amount of used memory is approximatly the same with
    // before running the program.
    return 0;
}