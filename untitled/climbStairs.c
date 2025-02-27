#include <stdio.h>

/* literally fibonacci */

int climbStairs(int n) {
  int result = 1;
  int ant = result;
  while(n > 1){
    result+=ant;
    ant=result-ant;
    n--;
  }
  return result;
}

int main() {
  int n = 6;
  printf("%d\n", climbStairs(n));
  return 0;
}