#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int* result = (int*)malloc(2 * sizeof(int));
  for (int i = 0; i < numsSize-1; i++) {
    for (int j = i+1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
        *returnSize = 2;
        return result;
      }
    }
  }
  *returnSize = 0;
  return NULL;
}

int main() {
  int nums[] = {2, 7, 11, 15};
  int numsSize = sizeof(nums) / sizeof(int);
  int target = 9;
  int returnSize;
  int* result = twoSum(nums, numsSize, target, &returnSize);
  if (returnSize == 0) {
    printf("No solution");
  }
  else {
    printf("%d %d\n", result[0], result[1]);
  }
  free(result);
  system("pause");
  return 0;
}