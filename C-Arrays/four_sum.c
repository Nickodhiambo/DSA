#include <stdlib.h>

// Takes an array of integers and returns
// for integers that must be equal to a target number passed
// as argument

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate space for the resulting array of quadruplets
    int maxQuadruplets = 1000;  // Set an initial maximum size (can be adjusted)
    int** result = (int**)malloc(maxQuadruplets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxQuadruplets * sizeof(int));
    *returnSize = 0;

    // Handle memory allocation failures
    if (result == NULL || *returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Iterate through the array to find quadruplets
    for (int i = 0; i < numsSize - 3; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j++) {
            // Skip duplicates
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[j] + nums[left] + nums[right];

                if (currentSum == target) {
                    // Found a quadruplet
                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}
