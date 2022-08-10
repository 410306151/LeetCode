#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int singleNumber(int* nums, int numsSize){
	if(numsSize == 1){
		return nums[0];
	}
	int xor = 0;

	// After xor operation, 1-bit becomes 0-bit, vice versa. A number apeears twice will set to 1-bit first, then set to 0-bit.
	for(int i = 0; i < numsSize; i++){
		xor ^= nums[i];
	}

	return xor;
}

int table_solution(int* nums, int numsSize){
	if(numsSize == 1){
		return nums[0];
	}

	int table[60001] = {0};

	for(int i = 0; i < numsSize; i++){
		table[nums[i] + 30000]++;
	}
	for(int i = 0; i < 60001; i++){
		if(table[i] == 1){
			return i - 30000;
		}
	}

	return 0;
}
//
//int main(){
//	int numsSize = 9;
//	int nums[9] = {1, 2, 5, 6, 5, 1, 4, 6, 2};
//	int answer;
//
//	answer = singleNumber(nums, numsSize);
//	printf("SIngle number of nums: %d\n", answer);
//
//	getch();
//
//	return 0;
//}
