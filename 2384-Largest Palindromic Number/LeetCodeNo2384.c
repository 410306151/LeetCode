#define bool char
#define true 1
#define false 0

char * largestPalindromic(char * num){
	int *arr = calloc(10, sizeof(int));
	int pos = 0;
	bool single = false;
	char *ans = calloc(strlen(num) + 2, sizeof(char));

	for(int i = 0; i < strlen(num); i++){
		arr[(num[i] - '0')]++;
	}
	// Look for biggest palindromic number;
	for(int i = 9; i > -1; i--){
		if(pos > 0 && i == 0 && arr[i] > 1){
			ans[pos] = '0';
			arr[i] -= 2;
			pos++;
			i++;
		} else if(i > 0 && arr[i] > 1){
			ans[pos] = '0' + i;
			arr[i] -= 2;
			pos++;
			i++;
		}
	}
	// Look for biggest single number;
	for(int i = 9; i > -1; i--){
		if(pos > 0 && i == 0 && arr[i] > 0){
			ans[pos] = '0';
			pos++;
			single = true;
			break;
		} else if(i > 0 && arr[i] > 0){
			ans[pos] = '0' + i;
			pos++;
			single = true;
			break;
		}
	}
	// Build palindrome
	if(single){
		for(int i = strlen(ans) - 2; i > -1; i--){
			ans[pos] = ans[i];
			pos++;
		}
	} else{
		for(int i = strlen(ans) - 1; i > -1; i--){
			ans[pos] = ans[i];
			pos++;
		}
	}
	if(pos == 0){
		ans[0] = '0';
		pos++;
	}
	ans[pos] = '\0';

	return ans;
}