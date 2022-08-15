#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int firstMissingPositive(int* nums, int numsSize){
	int *flag = calloc(numsSize + 2, sizeof(int));

	for(int i = 0; i < numsSize; i++){
		if(nums[i] > 0 && nums[i] < numsSize + 2){
			flag[nums[i]]++;
		}
	}
	for(int i = 1; i < numsSize + 1; i++){
		if(!flag[i]){
			return i;
		}
	}

	return numsSize + 1;
}