#include<stdio.h>
#include<stdbool.h>

bool isUgly(int n) {
  if (n <= 0) return false;

  while (n % 2 == 0) n /= 2;
  while (n % 3 == 0) n /= 3;
  while (n % 5 == 0) n /= 5;

  return n == 1;
}

int main() {
  int n = 7;
  if(isUgly(n)) {
    printf("%d Is Ugly", n);
  }
  else {
    printf("%d Is not Ugly", n);
  }
  return 0;
}