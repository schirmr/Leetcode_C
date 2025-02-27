#include <stdlib.h>
#include <stdio.h>

// Define a structure to hold both the number and its original index
struct Element {
    int value;
    int index;
};

// Comparator function to sort the array of elements by their value
int compare(const void *a, const void *b) {
    return ((struct Element*)a)->value - ((struct Element*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(*returnSize * sizeof(int));

    // Create an array of Element structs to keep track of the original indices
    struct Element* elements = (struct Element*)malloc(numsSize * sizeof(struct Element));
    for (int i = 0; i < numsSize; i++) {
        elements[i].value = nums[i];
        elements[i].index = i;
    }

    // Sort the elements array based on the value
    qsort(elements, numsSize, sizeof(struct Element), compare);

    // Two-pointer technique on the sorted array
    int i = 0, j = numsSize - 1;
    while (i < j) {
        int sum = elements[i].value + elements[j].value;

        if (sum == target) {
            res[0] = elements[i].index;
            res[1] = elements[j].index;
            free(elements);  // Free the allocated memory
            return res;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    free(elements);  // Free the allocated memory
    return NULL;  // Return NULL if no solution is found
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
