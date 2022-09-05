#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int binarySearch(int nums[], int target, int left, int right){
	int mid = (left + right) / 2;

	if(right == left && nums[left] != target){
		return -1;
	} else if(nums[mid] == target){
		return mid;
	}

	if(nums[mid] > target){
		// Left array
		return binarySearch(nums, target, left, mid);
	} else{
		// Right array
		return binarySearch(nums, target, mid + 1, right);
	}
}

int search(int* nums, int numsSize, int target){
	int rotatePos = -1;

	for(int i = 1; i < numsSize; i++){
		if(nums[i] < nums[i - 1]){
			rotatePos = i - 1;
			break;
		}
	}
	// Rotated array
	if(rotatePos != -1){
		if(target > nums[rotatePos]){
			// Target > maximum value of array
			return -1;
		} else if(target < nums[rotatePos + 1]){
			// Target < minimum value of array
			return -1;
		} else if(target >= nums[0]){
			return binarySearch(nums, target, 0, rotatePos);
		} else if(target < nums[0]){
			return binarySearch(nums, target, rotatePos + 1, numsSize - 1);
		}
	}
	// Array not rotate
	return binarySearch(nums, target, 0, numsSize - 1);
}