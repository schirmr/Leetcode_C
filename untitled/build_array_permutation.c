#include <stdio.h>
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int* result = (int*)malloc(sizeof(int) * numsSize);
  for (int i = 0; i < numsSize; i++) {
    result[i] = nums[nums[i]];
  }
  return result;
}

int main(void){
  int nums[] = {5,0,1,2,3,4};
  int numSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize;
  int *result = buildArray(nums,numSize, &returnSize);
  for (int i =0; i < numSize; i++) {
    printf("%d ", result[i]);
  }
  free(result);
  return 0;
}