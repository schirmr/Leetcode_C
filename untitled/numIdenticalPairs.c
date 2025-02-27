#include <stdio.h>

int numIdenticalPairs(int* nums, int numsSize) {
  int goodPairs = 0;
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if ((nums[i] == nums[j]) && i < j) {
        goodPairs++;
      }
    }
  }
  return goodPairs;
}

int main() {
  int nums[] = {1,2,3};
  int numsSize = sizeof(nums) / sizeof(int);
  printf("%d\n", numIdenticalPairs(nums, numsSize));
  return 0;
}