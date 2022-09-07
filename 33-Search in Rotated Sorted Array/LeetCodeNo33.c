#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int binarySearch(int nums[], int target, int left, int right){
    int mid = (left + right) / 2;
    
    if(right == left && nums[left] != target){
        return -1;
    }else if(nums[mid] == target){
        return mid;
    }
    
    if(target < nums[mid] && target > nums[right]){
        // Rotated array, target at left array
        return binarySearch(nums, target, left, mid);
    }else if(target > nums[mid] && target < nums[left]){
        // Rotated array, target at right array
        return binarySearch(nums, target, mid + 1, right);
    }else if(target < nums[left] || target > nums[right]){
        // Rotated array, target can be left or right array
        if(nums[mid] < nums[right]){
            // Left array
            return binarySearch(nums, target, left, mid);
        }else{
            // Right array
            return binarySearch(nums, target, mid + 1, right);
        }
    }else{
        // Regular binary search
        if(nums[mid] > target){
            // Left array
            return binarySearch(nums, target, left, mid);
        }else{
            // Right array
            return binarySearch(nums, target, mid + 1, right);
        }
    }
    
}

int search(int* nums, int numsSize, int target){
    
    return binarySearch(nums, target, 0, numsSize - 1);
}