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
    for (int i = 0; i < 10; i++)
        free(ptr[i]);
    // Si and so fields are equal to 0 during running of programm as nothing is swapped. 
    //It means that used in my computer replacement algorithm enables to 
    //find free memory for such amount of data without swapping. 
    return 0;
}