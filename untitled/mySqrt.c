#include <stdio.h>

/* assuming that the x >= 0*/

int mySqrt(int x) {
  int valueEsq = x/2, valueOdd;
  while(1){
    if(valueEsq*valueEsq == x)return valueEsq;
    if(valueEsq*valueEsq < x){
      valueOdd = valueEsq+1;
      if(valueOdd*valueOdd == x)return valueOdd;
      if(valueOdd*valueOdd > x)return valueEsq;
    }
    else{
      valueEsq = valueEsq/2;
      }
    valueEsq++;
  }
}

int main() {
  printf("%d\n", mySqrt(25));
  return 0;
}