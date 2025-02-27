#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
  int j = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[j] = nums[i];
      j++;
    }
  }
  return j;
}

int main() {
  int nums[] = {0, 1, 2, 2, 3, 0 , 4, 2};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  numsSize = removeElement(nums, numsSize, 2);
  printf("%d\n", numsSize);
  for(int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  system("pause");
}