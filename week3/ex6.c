#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void quickSort(int *array, int l, int r)
{ 
  int left = l; 
  int right = r; 
  int pivot = array[l];
  while (l < r) 
  {
    while ((array[r] >= pivot) && (l < r))
      r--; 
    if (l != r) 
    {
      array[l] = array[r]; 
      l++; 
    }
    while ((array[l] <= pivot) && (l < r))
      l++; 
    if (l != r) 
    {
      array[r] = array[l]; 
      r--; 
    }
  }
  array[l] = pivot;
  pivot = l;
  l = left;
  r = right;
  if (r > pivot)
    quickSort(array, pivot + 1, r);
  if (l < pivot) 
    quickSort(array, l, pivot - 1);
}


int main()
{
  int a[4] = {8, 6, 5, 7};
  quickSort(a, 0, 3); // вызов функции сортировки
  for (int i = 0; i<4; i++)
    printf("%d\n", a[i]);

  return 0;
}