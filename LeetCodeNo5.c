#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * longestPalindrome(char * s){
	char *middle = s, *left = s, *right = s, *ans_head = s, *answer;
	int max_length = 0;

	for(; *middle != NULL;){
		for(; *(right + 1) != NULL && *right == *(right + 1); right++){
			// Do nothing, duplicate characters consider palindromic
		}
		middle = right + 1;

		for(; left > s && *(right + 1) != NULL && *(left - 1) == *(right + 1); left--, right++){
		}
		if((right - left) + 1 > max_length){
			ans_head = left;
			max_length = (right - left) + 1;
		}
		left = middle;
		right = middle;
	}
	answer = calloc((max_length + 1), sizeof(char));
	strncpy(answer, ans_head, max_length);

	return answer;
}

//int main(){
//	char *s = "babad";
//	char *answer;
//
//	answer = longestPalindrome(s);
//	printf("%s\n", answer);
//
//	getch();
//
//	return 0;
//}
