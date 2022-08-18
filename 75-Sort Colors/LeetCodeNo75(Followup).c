void swap(int nums[], int a, int b){
	int temp;

	temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void sortColors(int* nums, int numsSize){
	int left = 0, right = numsSize - 1;

	for(int i = 0; i < numsSize; i++){
		if(nums[i] == 2 && i < right){
			swap(nums, i, right);
			i--;
			right--;
		} else if(nums[i] == 0){
			swap(nums, i, left);
			left++;
		}
	}
}