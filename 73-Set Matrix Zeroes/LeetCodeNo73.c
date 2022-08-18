void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	bool *col = calloc(*matrixColSize, sizeof(bool));
	bool *row = calloc(matrixSize, sizeof(bool));

	// Use m + n space to memorize which row and column need to set to 0
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < *matrixColSize; j++){
			if(!matrix[i][j]){
				col[j] = true;
				row[i] = true;
			}
		}
	}

	// Setting row elements to 0
	for(int i = 0; i < matrixSize; i++){
		if(row[i]){
			for(int j = 0; j < *matrixColSize; j++){
				matrix[i][j] = 0;
			}
		}
	}
	// Setting column elements to 0
	for(int i = 0; i < *matrixColSize; i++){
		if(col[i]){
			for(int j = 0; j < matrixSize; j++){
				matrix[j][i] = 0;
			}
		}
	}
}