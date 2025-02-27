#include <stdio.h>

int maximizeSum(int *nums, int numsSize, int k) {
    int max = nums[0];
    int result;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    result = max;
    while (k > 1) {
        result += max + k - 1;
        k--;
    }
    return result;
}

int main() {
    int nums[] = {5,5,5};
    int k = 2;
    printf("%d\n", maximizeSum(nums, sizeof(nums) / sizeof(int), k));
    return 0;
}
