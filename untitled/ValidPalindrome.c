#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
  int j = 0;
  for(int i = 0; s[i] != '\0'; i++) {
     if(s[i] >= 65 && s[i] <= 90) {
       s[j] = s[i] + 32;
       j++;
     }
     else if((s[i] < 97 || s[i] > 122 ) && (s[i+1] >= 97 && s[i+1] <= 122) && (s[i] < 48 && s[i] > 57)) {
       s[j] = s[i+1];
       i++;
       j++;
     }
     else if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
      s[j] = s[i];
       j++;
    }
    }
  s[j] = '\0';
  --j;
  for (int i = 0; i < j; i++, j--) {
    printf("s[i]:%c, s[j]:%c\n", s[i], s[j]);
    if(s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

int main() {
  char str[] = "1bb1";
  if(isPalindrome(str)) {
    printf("Palindrome\n");
  }
  else {
    printf("Not a palindrome\n");
  }
  return 0;
}