#include<stdio.h>
#include<string.h>

int count(char str[256], char);
void countAll(char str[256]);
char counted[100];

int main(int argc, char *argv[]) {
    char str[256];
    int len;
    printf("enter string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)  {  
    if (str[i] >= 65 && str[i] <= 90)  
        str[i] = str[i] + 32;
    }
    countAll(str);
    return 0;
}

int count(char str[256], char symb) {
    int res = 0, len;
    for (int i = 0; i < strlen(str); ++i) {
        if (symb == str[i])
            res++;
    }
    return res;
}

void countAll(char str[256]) {
    for (int i = 0; i < strlen(str); ++i) {
        printf("%c: %d", str[i], count(str, str[i]));
        if (i < strlen(str) - 1) printf(", ");
    }
}