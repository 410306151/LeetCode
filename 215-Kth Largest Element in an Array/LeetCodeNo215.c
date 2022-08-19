int partialQuickSort(int nums[], int left, int right){
	int temp, pivot;

	for(int i = left, j = right;;){
		while(nums[j] >= nums[left] && j > left) j--;
		while(nums[i] <= nums[left] && i < j) i++;
		if(i == j){
			temp = nums[i];
			nums[i] = nums[left];
			nums[left] = temp;
			pivot = i;
			break;
		} else{
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}

	return pivot;
}

int findKthLargest(int* nums, int numsSize, int k){
	int pos, left = 0, right = numsSize - 1;

	while(1){
		pos = partialQuickSort(nums, left, right);
		if(pos == (numsSize - k)){
			return nums[pos];
		} else if(pos > (numsSize - k)){
			right = pos - 1;
		} else{
			left = pos + 1;
		}
	}
}