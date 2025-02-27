#include <stdio.h>

int lengthOfLastWord(char* s) {
  int tam = 0, x = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
      if (x == 1) {
        tam = 1;
        x = 0;
      }
      else tam++;
    }
    else if (tam>0)x = 1;
  }
  return tam;
}

int main() {
  printf("%d", lengthOfLastWord("   fly me   to   the moon  "));
  return 0;
}