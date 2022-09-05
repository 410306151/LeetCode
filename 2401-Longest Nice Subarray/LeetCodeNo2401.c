

int longestNiceSubarray(int* nums, int numsSize){
    int ans = 1;
    int skip = 0;
    
    for(int left = 0, right = left + 1; right < numsSize;){
        if((nums[left] & nums[right]) == 0){
            // Left element & Right element = 0
            skip = 0;
            // Check all elements in subarray will also be 0 with Right element
            for(int i = left; i < right; i++){
                if((nums[i] & nums[right]) != 0){
                    left = i + 1;
                    skip = 1;
                    break;
                }
            }
            // If new subarray is bigger than known subarray
            if(ans < (right - left + 1)){
                ans = right - left + 1;
            }
            // If all element are 0 to each another with AND operation in certain subarray, right index move on 
            if(!skip){
                right += 1;
            }
        }else{
            // Reset window
            left += 1;
            right = left + 1;
        }
    }
    
    return ans;
}