

int longestNiceSubarray(int* nums, int numsSize){
	int ans = 1;

	for(int left = 0, right = left + 1; right < numsSize;){
		if((nums[left] & nums[right]) == 0){
			// Left element AND Right element = 0
			for(int i = left; i < right; i++){
				if((nums[i] & nums[right]) != 0){
					left = i + 1;
					break;
				}
			}
			if(ans < (right - left + 1)){
				ans = right - left + 1;
			}
			right += 1;
		} else{
			left += 1;
			right = left + 1;
		}
	}

	return ans;
}