#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void reverseString(char* s, int sSize){
	char temp;

	for(int i = 0, j = sSize - 1; i < j; i++, j--){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}