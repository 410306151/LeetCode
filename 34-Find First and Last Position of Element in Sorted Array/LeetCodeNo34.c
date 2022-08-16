/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void binarySearch(int nums[], int numsSize, int target, int head, int tail, int ans[]){
	int middle = (head + tail) / 2;

	if(nums[middle] == target){
		if(ans[0] == -1){
			ans[0] = middle;
			ans[1] = middle;
		} else if(ans[0] > middle){
			ans[0] = middle;
		} else if(ans[1] < middle){
			ans[1] = middle;
		}
	}
	// Left array
	if(middle > head && nums[middle] >= target){
		binarySearch(nums, numsSize, target, head, middle, ans);
	}
	// Right array
	if(tail > middle && nums[middle] <= target){
		binarySearch(nums, numsSize, target, middle + 1, tail, ans);
	}
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *ans = calloc((*returnSize = 2), sizeof(int));

	ans[0] = ans[1] = -1;
	if(numsSize < 1){
		return ans;
	} else if(numsSize == 1){
		if(nums[0] == target){
			ans[0] = ans[1] = 0;
		}
		return ans;
	}

	binarySearch(nums, numsSize, target, 0, numsSize - 1, ans);

	return ans;
}