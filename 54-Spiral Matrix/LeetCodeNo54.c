#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
	int top = 0, bottom = matrixSize - 1, left = 0, right = *matrixColSize - 1;
	int *ans = calloc(matrixSize * (*matrixColSize), sizeof(int));
	int pos = 0;

	*returnSize = matrixSize * (*matrixColSize);
	for(; left <= right || top <= bottom;){
		if(top <= bottom){
			// Top
			for(int j = left; j <= right; j++){
				ans[pos++] = matrix[top][j];
			}
			top += 1;
		}
		if(left <= right){
			// Right
			for(int j = top; j <= bottom; j++){
				ans[pos++] = matrix[j][right];
			}
			right -= 1;
		}
		if(top <= bottom){
			// Bottom
			for(int j = right; j >= left; j--){
				ans[pos++] = matrix[bottom][j];
			}
			bottom -= 1;
		}
		if(left <= right){
			// Left
			for(int j = bottom; j >= top; j--){
				ans[pos++] = matrix[j][left];
			}
			left += 1;
		}
	}

	return ans;
}