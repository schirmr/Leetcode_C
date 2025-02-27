#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
  int* newNums = (int*)malloc(sizeof(int) * numsSize);
  int leftSum[numsSize];
  int rightSum[numsSize];
  leftSum[0] = 0;
  rightSum[numsSize-1] = 0;
  for (int i = 1; i < numsSize; i++){
    leftSum[i] = leftSum[i-1] + nums[i-1];
  }
  for (int i = numsSize-2; i >= 0; i--) {
    rightSum[i] = rightSum[i+1] + nums[i+1];
  }
  for (int i = 0; i < numsSize; i++) {
    printf("L: %d  R: %d \n", leftSum[i], rightSum[i]);
    if (leftSum[i] > rightSum[i]) {
      newNums[i] = leftSum[i] - rightSum[i];
    }
    else {
      newNums[i] = rightSum[i] - leftSum[i];
    }
  }
  *returnSize = numsSize;
  return newNums;
}

int main() {
  int nums[] = {10, 4, 8, 3};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize;
  int* result = leftRightDifference(nums, numsSize, &returnSize);
  for (int i=0; i < numsSize; i++) {
    printf("nums[%d] = %d\n", i, result[i]);
  }
  free(result);
  return 0;
}