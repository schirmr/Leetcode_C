#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
  if(numsSize<2)return;
  int j=0;
  for(int i=1;i<numsSize;i++){
    if(nums[j]!=0)j++;
    else if(nums[j]==0&&nums[i]!=0){
      nums[j]=nums[i];
      nums[i]=0;
      j++;
    }
  }
}

int main() {
  int nums[] = {0,1,0,3,12};
  int numsSize = sizeof(nums) / sizeof(int);
  moveZeroes(nums, numsSize);
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  return 0;
}