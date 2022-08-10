#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int *merge(int *nums1, int nums1Size, int *nums2, int nums2Size){
	int *new_nums = calloc(nums1Size + nums2Size, sizeof(int));

	for(int i = 0, j = 0, k = 0; j < nums1Size || k < nums2Size; i++){
		if(j >= nums1Size){
			new_nums[i] = nums2[k];
			k++;
		} else if(k >= nums2Size){
			new_nums[i] = nums1[j];
			j++;
		} else if(nums1[j] < nums2[k]){
			new_nums[i] = nums1[j];
			j++;
		} else{
			new_nums[i] = nums2[k];
			k++;
		}
	}

	return new_nums;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	int *array;
	int middle;
	double temp;

	array = merge(nums1, nums1Size, nums2, nums2Size);
	middle = (nums1Size + nums2Size) / 2;
	if((nums1Size + nums2Size) % 2){
		return array[middle];
	} else{
		return (array[middle - 1] + array[middle]) / 2.0;
	}
}
//
//int main(){
//
//
//	getch();
//
//	return 0;
//}
