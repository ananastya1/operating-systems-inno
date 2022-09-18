#include <stdio.h>
#include <stdlib.h>

int foo(int age);

int main() {
  const int x = 10;
  const int* q = &x;
  const int* const p = (const int *) malloc(sizeof(x) * 5);
  int *k = p;
  for (int i = 0; i < 5; ++i) {
    *(k + i) = &x;
    printf("%p\n", k + i);
  }
  printf("%s\n", "enter 5 numbers: ");
  for (int i = 0; i < 5; ++i) {
    scanf("%d", k + i);
    *(k + i) = foo(*(k + i));
    printf("%d\n", *(k + i));
  }
  free(p);
  return EXIT_SUCCESS;
}

int foo(int age) {
  int res;
  res = 2022 - age;
  return res;
}