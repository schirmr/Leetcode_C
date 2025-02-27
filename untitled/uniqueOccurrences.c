#include <stdio.h>
#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {

}

int main() {
  int arr[] = {1,2,2,1,1,3};
  int arrSize = sizeof(arr) / sizeof(arr[0]);
  if(uniqueOccurrences(arr, arrSize)) {
    printf("True\n");
  }
  else{
    printf("False\n");
  }
  return 0;
}