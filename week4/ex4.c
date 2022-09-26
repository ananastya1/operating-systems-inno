#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    char array[100];
    for ( ; ; ) {
        printf("Enter command: ");
        fgets(array, 100, stdin);
        if (strcmp(array, "exit\n") == 0) return EXIT_SUCCESS;
        else system(array);
    }
    return 0;
}