#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define tableSize 800

struct element{
	int num;
	int index;
	struct element *next;
};

void init_table(struct element *table){
	for(int i = 0; i < tableSize; i++){
		table[i].num = 0;
		table[i].index = -1;
		table[i].next = NULL;
	}
}

void free_table(struct element *table){
	for(int i = 0; i < tableSize; i++){
		if(table[i].next != NULL){
			struct element *temp = table[i].next;
			while(temp->next != NULL){
				table->next = temp->next;
				free(temp);
				temp = table->next;
			}
			free(temp);
		}
	}
}

void insert_table(struct element *table, int index, int value){
	struct element *newNode = malloc(sizeof(struct element));
	struct element *curNode;
	int position = abs(value % tableSize);

	newNode->num = value;
	newNode->index = index;
	newNode->next = NULL;
	curNode = table + position;
	while(curNode->next != NULL){ // First element is a head of linked-list, we don't use it to store data
		curNode = curNode->next;
	}
	curNode->next = newNode;
}

int find_table(struct element *table, int target_value){
	int position = abs(target_value % tableSize);
	int target = -1;
	struct element *temp = table + position; // Using pointer like an array

	while(temp->next != NULL){
		temp = temp->next;
		if(temp->num == target_value){
			return temp->index;
		}
	}
	return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	// This method is using hash table to find the target
	int *answer = malloc(sizeof(int) * (*returnSize = 2));
	int result = -1;
	struct element *table = malloc(sizeof(struct element) * tableSize);

	init_table(table);
	for(int i = 0; i < numsSize; i++){
		result = find_table(table, target - nums[i]);
		if(result != -1){
			answer[0] = result;
			answer[1] = i;
			return answer;
		}
		insert_table(table, i, nums[i]);
	}

	free_table(table);

	return answer;
}

//int main(){
//	int *result, returnSize;
//	int nums[4];
//
//	nums[0] = -3, nums[1] = 4, nums[2] = 3, nums[3] = 15;
//	result = twoSum(nums, 4, 0, &returnSize);
//
//	printf("%d, %d\n", result[0], result[1]);
//	getch();
//
//	return 0;
//}
