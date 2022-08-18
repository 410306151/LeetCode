
void quickSort(int nums[], int l, int r){
	int pivot, temp;

	if(r - l < 1){
		return;
	}
	for(int i = l, j = r;;){
		while(nums[j] >= nums[l] && j > l) j--;
		while(nums[i] <= nums[l] && i < j) i++;
		if(i == j){
			pivot = i;
			temp = nums[l];
			nums[l] = nums[i];
			nums[i] = temp;
			break;
		} else{
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}

	quickSort(nums, l, pivot - 1);
	quickSort(nums, pivot + 1, r);
}

void sortColors(int* nums, int numsSize){
	quickSort(nums, 0, numsSize - 1);
}