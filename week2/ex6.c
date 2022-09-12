#include<stdio.h>



int main(int argc, char *argv[]) {
    int number, symb;
    printf("enter number: ");
    scanf("%d", &number);
    for (int i = 1; i <= number; ++i) {
        symb = i;
        while (symb-- > 0) {
            putchar('*');
        }
        putchar('\n');
    }
    putchar('\n');
    for (int i = 1; i <= number / 2 + number % 2; ++i) {
        symb = i;
        while (symb-- > 0) {
            putchar('*');
        }
        putchar('\n');
    }
    for (int i = number / 2; i > 0; --i) {
        symb = i;
        while (symb-- > 0) {
            putchar('*');
        }
        putchar('\n');
    }
    putchar('\n');
    for (int i = 1; i <= number; ++i) {
        symb = number;
        while (symb-- > 0) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}