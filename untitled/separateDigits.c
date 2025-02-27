#include <stdio.h>

int* separateDigits(int* nums, int numsSize, int* returnSize) {

}

int main() {
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int numsSize = sizeof(nums) / sizeof(int);
  int* returnSize = numsSize;
  nums = separateDigits(nums, numsSize, returnSize);
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  return 0;
}