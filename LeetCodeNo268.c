#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//int array_record(int* nums, int numsSize){
//	int *table = calloc(numsSize + 1, sizeof(int));
//
//	for(int i = 0; i < numsSize; i++){
//		table[nums[i]] = 1;
//	}
//	for(int i = 0; i < numsSize + 1; i++){
//		if(!table[i]){
//			return i;
//		}
//	}
//
//	return 0;
//}

int missingNumber(int* nums, int numsSize){
	int answer = numsSize;

	for(int i = 0; i < numsSize; i++){
		answer ^= nums[i] ^ i;
	}

	return answer;
}

//int main(){
//	int test[4] = {3,0,2,4};
//	int answer;
//
//	answer = missingNumber(test, 7);
//	printf("%d ", answer);
//
//	getch();
//
//	return 0;
//}

