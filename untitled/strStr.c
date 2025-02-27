#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
  int len = strlen(needle);
  if (len > strlen(haystack)) {
    return -1;
  }
  int i = 0, j = 0, index = -1;
  while (haystack[i] != '\0') {
    if(j == len) {
      return index;
    }
    if (haystack[i] == needle[j] && index == -1) {
      index = i;
      j++;
      i++;
    }
    else if (haystack[i] == needle[j] && index != -1) {
      i++;
      j++;
    }
    else if (haystack[i] != needle[j] && index == -1) {
      i++;
    }
    else {
      i = index + 1;
      index = -1;
      j = 0;
    }
    if (haystack[i] == '\0' && j < len) return -1;
  }
  return index;
}

int main() {
  char haystack[] = "mississippi";
  char needle[] = "issipi";
  printf("%d\n", strStr(haystack, needle));
}