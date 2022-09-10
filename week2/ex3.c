#include<stdio.h>
#include<math.h>

void convert(long long int, int, int);

int main(int argc, char *argv[])
{
    long long int number, pr;
    int from, to;
    printf("enter number to convert: ");
    scanf("%lld", &number);
    pr = number;
    printf("enter source number system: ");
    scanf("%d", &from);
        while (pr != 0) {
        int n = pr % 10;
        if (n > from) {
            printf("cannot convert!");
            return 0;
        }
        pr /= 10;
    }
    printf("enter target number system: ");
    scanf("%d", &to);
    if (from < 2 || from > 10 || to < 2 || to > 10) {
        printf("cannot convert!");
    }
    else {
            convert(number, from, to);
    }
    return 0;
}

void convert(long long int val, int from, int to){
    long long int res = 0;
    int i = 0;
    while(val != 0)
    {
      res += (val % to)*pow(from, i++);
      val /= to;
    }
    printf("%lld", res);
}