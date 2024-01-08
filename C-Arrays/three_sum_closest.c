#include <stdlib.h>

// Sums three numbers in an array and returns
// the sum that is closest to a target value

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize the closest sum variable
    int closestSum = nums[0] + nums[1] + nums[2];

    // Iterate through the array to find closest sum
    for (int i = 0; i < numsSize - 2; i++)
    {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update the closestSum if currentSum is closer to the target
            if (abs(target - currentSum) < abs(target - closestSum))
            {
                closestSum = currentSum;
            }
            if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return (closestSum);
}