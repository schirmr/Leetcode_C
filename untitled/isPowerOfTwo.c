#include<stdio.h>
#include<stdbool.h>

/* 100 & 011 == 0 (binary 100 is power of two)
 * 101 & 100 == 1 (binary 101 is not power of two)
 * 10100 & 10011 == 1 (binary 10100 is not power of two)
 * & = AND bit a bit
 */

bool isPowerOfTwo(int n) {
  if (n <= 0) return false;
  return (n & (n - 1)) == 0;
}

int main() {
  int n = 32;
  if(isPowerOfTwo(n)) {
    printf("%d is a power of two\n", n);
  }
  else {
    printf("%d is not a power of two\n", n);
  }
  return 0;
}