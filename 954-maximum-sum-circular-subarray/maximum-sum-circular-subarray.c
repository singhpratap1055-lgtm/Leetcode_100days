#include <limits.h>

/**
 * @param nums: integer array
 * @param numsSize: size of array
 * @return: maximum circular subarray sum
 */
int maxSubarraySumCircular(int* nums, int numsSize) {
    
    int totalSum = 0;
    
    int maxSum = nums[0];
    int currMax = 0;
    
    int minSum = nums[0];
    int currMin = 0;
    
    for(int i = 0; i < numsSize; i++) {
        
        // Standard Kadane for maximum subarray
        currMax = (currMax > 0) ? currMax + nums[i] : nums[i];
        if(currMax > maxSum)
            maxSum = currMax;
        
        // Kadane for minimum subarray
        currMin = (currMin < 0) ? currMin + nums[i] : nums[i];
        if(currMin < minSum)
            minSum = currMin;
        
        totalSum += nums[i];
    }
    
    // If all numbers are negative
    if(maxSum < 0)
        return maxSum;
    
    // Return maximum of normal and circular
    return (maxSum > (totalSum - minSum)) ? maxSum : (totalSum - minSum);
}