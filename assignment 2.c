#include <stdio.h>


int findMin(int* nums, int numsSize) { 
    int left = 0;
    int right = numsSize - 1;
    while (nums[left] > nums[right]) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
        if (nums[mid] < nums[mid - 1]) return nums[mid];
        if (nums[mid] < nums[right]) 
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return nums[left];
}

int main() {
    
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int minElement = findMin(nums, numsSize);
    printf("The minimum element in the array is: %d\n", minElement);

    return 0;
}