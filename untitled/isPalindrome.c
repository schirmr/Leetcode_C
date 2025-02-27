#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    long int inverse = 0; /* long int to leetcode */
    int original = x;
    while(x > 0){
      inverse= inverse * 10 + (x % 10);
      x/=10;
    }
    return original == inverse;
}

int main() {
  int x = 1234567899;
  if(isPalindrome(x)) {
    printf("Palindrome\n");
  }
  else {
    printf("Not a palindrome\n");
  }
  return 0;
}