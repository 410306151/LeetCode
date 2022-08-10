#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//int* condition_solution(int* nums, int numsSize, int* returnSize){
//	int *answer = calloc(numsSize, sizeof(int));
//	int total = 1;
//	int has_zero = 0, all_zero = 1;
//	*returnSize = numsSize;
//
//	for(int i = 0; i < numsSize; i++){
//		if(nums[i] != 0){
//			total *= nums[i];
//			all_zero = 0;
//		} else{
//			if(has_zero >= 1){
//				has_zero = 2;
//			} else{
//				has_zero = 1;
//			}
//		}
//	}
//	for(int i = 0; i < numsSize; i++){
//		if((all_zero) || (has_zero == 2) || (nums[i] != 0 && has_zero >= 1)){
//			answer[i] = 0;
//		} else if(!nums[i]){
//			answer[i] = total;
//		} else{
//			answer[i] = total / nums[i];
//		}
//	}
//
//	return answer;
//}

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
	int *answer = calloc(numsSize, sizeof(int));
	int temp = 1;

	answer[0] = 1;
	*returnSize = numsSize;
	for(int i = 1; i < numsSize; i++){
		answer[i] = answer[i - 1] * nums[i - 1];
	}
	for(int i = numsSize - 1; i > -1; i--){
		answer[i] = answer[i] * temp;
		temp *= nums[i];
	}

	return answer;
}

//int main(){
//	int test[10] = {1,-1,3,0,-3,5,6};
//	int *answer, returnSize;
//
//	answer = productExceptSelf(test, 7, &returnSize);
//	for(int i = 0; i < returnSize; i++){
//		printf("%d ", answer[i]);
//	}
//
//	getch();
//
//	return 0;
//}