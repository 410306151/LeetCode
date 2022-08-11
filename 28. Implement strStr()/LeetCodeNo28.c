#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int strStr(char * haystack, char * needle){
	int flag;

	for(int i = 0; i < strlen(haystack); i++){
		if(haystack[i] == needle[0]){
			flag = 1;
			for(int j = 0; j < strlen(needle); j++){
				if(haystack[i + j] != needle[j]){
					flag = 0;
					break;
				}
			}
			if(flag){
				return i;
			}
		}
	}

	return -1;
}

int strStr(char * haystack, char * needle){
	//Used KMP algorithm
	// flag = needle matched
	// skip = wether skip to next duplicated letter or not (only happens when the first letter of needle occurred more than once.)
	int flag, skip, next, words = 0;

	for(int i = 0; i < strlen(haystack); i++){
		if(haystack[i] == needle[0]){
			flag = 1;
			skip = next = 0;
			// If we found some matched letters from previous string, skip those matched letters to speed up.
			for(int j = 1 + words, words = 0; j < strlen(needle); j++){
				// If the first letter is duplicated in needle.
				// First, remember the position of the first letter occurred.
				// Second, count how many letters matched to needle.
				if(!skip && haystack[i + j] == needle[0]){
					// First letter occurred second time in needle, remember the position.
					next = j;
					skip = 1;
				} else if(skip && haystack[i + j] == needle[words]){
					// Find how many duplicated letter matched to needle.
					words++;
				}
				if(haystack[i + j] != needle[j]){
					flag = 0;
					break;
				}
			}
			if(flag){
				return i;
			} else if(skip){
				i = i + next + words - 1;
			}
		}
	}

	return -1;
}