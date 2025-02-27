#include <stdio.h>
#include <stdlib.h>

/* 1<= n <= 10^5 = 100000 = 6 nums max */

int subtractProductAndSum(int n) {
  int product = 1, sum = 0, i, j;
  if (n<10) return 0;
  for (i=10;n>0;i*=10) {
    j = n%10;
    product *= j;
    sum += j;
    n/=10;
  }
  return product - sum;
}

int main(void) {
  int n = 4421;
  printf("%d\n", subtractProductAndSum(n));
  return 0;
}