#include <stdio.h>

typedef int elem_t;

int binary_search(const elem_t a[], const int n, const elem_t x){
  int left = 0, right = n - 1, mid;
  while(left <= right){
    mid = left + (right - left) / 2;
    if(x > a[mid])
      left = mid + 1;
    else  if(x < a[mid])
      right = mid - 1 ;
    else
      return mid;
  }
  return -(left+1);
}


int main() {
  int a[] = {2,3,6,9,23,43,45,56,89};
  printf("%d\n", binary_search(a, 9, 57));
}
