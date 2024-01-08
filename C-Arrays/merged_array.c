#include <stdlib.h>

// Computes the median of an array

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Calculate the total size of the merged array
    int totalSize = nums1Size + nums2Size;

    // Allocate memory for merged array
    int* mergedArray = (int*)malloc(totalSize * sizeof(int));

    // Merge the two arrays
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            mergedArray[k++] = nums1[i++];
        }
        else
        {
            mergedArray[k++] = nums2[j++];
        }
        
    }

    // Copy unmatched items from both arrays
    while (i < nums1Size)
    {
        mergedArray[k++] = nums1[i++];
    }

    while (j < nums2Size)
    {
        mergedArray[k++] = nums2[j++];
    }

    // Compute the median
    double median;
    if (totalSize % 2 == 0)
    {
        // Total size is even, take an average of the middle two
        median = (mergedArray[(totalSize / 2) - 1] + mergedArray[totalSize / 2]) / 2.0;
    }
    else
    {
        // If the total size is odd, take the middle element
        median = mergedArray[totalSize / 2];
    }
    free(mergedArray);
    return median;
}