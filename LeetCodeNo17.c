#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void recursion(char **output, char *buff, char *temp, char letter_table[8][5], int digits_index, int table_position, int *returnSize){
	int sub_position = 0;

	buff[digits_index - 1] = letter_table[temp[digits_index - 1] - '0' - 2][table_position];
	if(temp[digits_index] == NULL){
		output[*returnSize] = calloc(digits_index + 1, sizeof(char));
		memcpy(output[*returnSize], buff, digits_index);
		(*returnSize)++;
		return;
	}
	digits_index++;
	for(; sub_position < 4 && letter_table[temp[digits_index] - '0' - 2][sub_position] != ' '; sub_position++){
		recursion(output, buff, temp, letter_table, digits_index, sub_position, returnSize);
	};
	return;
}

char ** letterCombinations(char * digits, int* returnSize){
	char *temp = digits;
	char **output;
	char letter_table[8][5] = {"abc ", "def ", "ghi ", "jkl ", "mno ", "pqrs", "tuv ", "wxyz"};
	char *buff;
	int array_size = 1;

	*returnSize = 0;
	if(*digits == '\0'){
		return NULL;
	}

	for(; *temp != NULL; temp++){
		if(*temp == '7' || *temp == '9'){
			array_size *= 4;
		} else{
			array_size *= 3;
		}
	}
	temp = digits;
	output = (char **)calloc(array_size * strlen(digits), sizeof(char *));
	buff = calloc(strlen(digits), sizeof(char));
	for(int table_position = 0; table_position < 4 && letter_table[(*temp) - '0' - 2][table_position] != ' '; table_position++){
		recursion(output, buff, temp, letter_table, 1, table_position, returnSize);
		//printf("%c\n", letter_table[(*temp) - '0' - 2][table_position]);
	}

	return output;
}
//
//int main(){
//	char *s = "273";
//	char **answer;
//	int returnSize;
//
//	answer = letterCombinations(s, &returnSize);
//	for(int i = 0; i < returnSize; i++){
//		printf("%s\n", answer[i]);
//	}
//
//	getch();
//
//	return 0;
//}
