#include <stdio.h>

char* toLowerCase(char* s) {
  for(int i = 0; s[i] != '\0'; i++) {
    if(s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = s[i]+32;
    }
  }
  return s;
}

int main() {
  char s[] = "WORld";
  printf("%s\n", toLowerCase(s));
  return 0;
}