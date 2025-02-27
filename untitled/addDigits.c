#include <stdio.h>

/*int addDigits(int num) {
    int oneDigit = 0;
    while(num>0) {
        printf("oneDigit: %d\nnum: %d\n", oneDigit, num);
        oneDigit+= num % 10;
        if (num / 10 == 0 && oneDigit < 10) return oneDigit;
        if (num / 10 != 0) {
            num/=10;
        }
        else {
            num = oneDigit;
            oneDigit = 0;
        }
    }
    return oneDigit;
}*/

/*
 * Could you do it without any loop/recursion in O(1) runtime?
 */

int addDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + (num - 1) % 9;
    }
}

int main() {
  printf("%d\n", addDigits(38));
  return 0;
}