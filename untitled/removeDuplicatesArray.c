#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  if (numsSize == 0) return 0;
  int k = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] != nums[i - 1]) {
      nums[k] = nums[i];
      k++;
    }
  }
  return k;
}

int main() {
  int nums[] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,3,3,3,3,3,4,5};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int k = removeDuplicates(nums, numsSize);
  printf("k = %d\n", k);
  for (int i = 0; i < k; i++) {
    printf("%d ", nums[i]);
  }
  return 0;
}