#define bool char
#define true 1
#define false 0

bool checkDistances(char * s, int* distance, int distanceSize){
	int *range = calloc(26, sizeof(int));
	int pos = 0;

	for(int i = 0; i < 26; i++){
		range[i] = -1;
	}
	for(int i = 0; i < strlen(s); i++){
		pos = (int)(s[i] - 'a');
		if(range[pos] != -1){
			range[pos] = i - (range[pos] + 1);
		} else{
			range[pos] = i;
		}
	}
	for(int i = 0; i < distanceSize; i++){
		if(range[i] != -1 && distance[i] != range[i]){
			return false;
		}
	}

	return true;
}