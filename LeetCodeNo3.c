#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int lengthOfLongestSubstring(char * s){
	char *head = s, *end = s;
	int total_length = 0;
	int char_table[128] = {0};

	for(; *end != NULL; end++){
		if(char_table[*end] == 0){
			char_table[*end] = 1;
		} else{
			if(total_length < (end - head)){
				total_length = (end - head);
			}
			for(; *head != *end; head++){
				char_table[*head] = 0;
			}
			head++;
		}
	}
	if(total_length < (end - head)){
		total_length = (end - head);
	}
	printf("%d\n", total_length);

	return total_length;
}

//int main(){
//	char *s = "abcabcbb";
//
//	lengthOfLongestSubstring(s);
//
//	getch();
//
//	return 0;
//}
