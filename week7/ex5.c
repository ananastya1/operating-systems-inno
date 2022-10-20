#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **s = malloc(sizeof(char *)); // here was an error, we need allocate memory for a pointer to a char
    char foo[] = " Hello World ";
    *s = foo;
    printf("s is %s\n", *s); // here was an error, we need to dereference the pointer to a char
    s[0] = foo;
    printf("s [0] is %s\n", s[0]);
    free(s);
    return (0);
}