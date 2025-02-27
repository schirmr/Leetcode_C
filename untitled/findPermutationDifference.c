#include <stdio.h>

int findPermutationDifference(char* s, char* t) {
  int result = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] != t[i]){
      for (int j = 0; t[j] != '\0'; j++) {
        if(s[i] == t[j]){
          if(i > j){
            result+= i - j;
          }
          else{
            result+= j - i;
          }
        }
    }}
  }
  return result;
}

int main(void){
  char* s = "abcde";
  char* t = "edbac";
  printf("%d\n", findPermutationDifference(s, t));
  return 0;
}