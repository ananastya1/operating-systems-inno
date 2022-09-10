#include <stdio.h>
#include <string.h>


char array[256];
char letter;
int counter;

int main(int argc, char *argv[]) {
    for (counter = 0; (letter = getchar()) != '.' && letter != '\n'; ++counter ) {
          array[counter] = letter;
    }
    putchar('"');
    while (counter > 0) {
        counter--, putchar(array[counter]);
    }
    putchar('"');
    putchar('\n');

    return 0;
}