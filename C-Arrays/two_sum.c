#include <stdlib.h>
#include <stdio.h>

// Finds any two elements in array whose sum
// is equal to a target number
// Returns a sub array of the two numbers

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Initialize returnSize
    *returnSize = 2;

    // Allocate memory for the result array
    int* result = (int*)malloc(2 * sizeof(int));

    // Check for memory allocation failure
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Nested loop to find the pair of indices
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                // Indices found, store them in the result array
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    // If no such pair is found, set returnSize to 0 and return NULL
    *returnSize = 0;
    free(result);
    return NULL;
}

int main() {
    // Example usage
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize > 0) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
