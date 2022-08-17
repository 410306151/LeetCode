

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
void search(int nums[], int numsSize, int *returnSize, int **returnColumnSizes, int pos, int size, int **ans, int temp[]){
	for(int i = pos; i < numsSize; i++){
		temp[size - 1] = nums[i];
		// Go to next element
		search(nums, numsSize, returnSize, returnColumnSizes, i + 1, size + 1, ans, temp);
		// Allocate space and copy subset to ans
		ans[*returnSize] = (int *)calloc(size, sizeof(int));
		(*returnColumnSizes)[*returnSize] = size;
		for(int j = 0; j < size; j++){
			ans[*returnSize][j] = temp[j];
		}
		*returnSize += 1;
	}
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int **ans = (int **)calloc(pow(2, numsSize), sizeof(int *));
	int *temp = calloc(numsSize, sizeof(int));

	*returnSize = 1;
	*returnColumnSizes = (int *)calloc(pow(2, numsSize), sizeof(int));
	// First element is empty set
	(*returnColumnSizes)[0] = 0;
	// Backtracking
	search(nums, numsSize, returnSize, returnColumnSizes, 0, 1, ans, temp);
	free(temp);

	return ans;
}