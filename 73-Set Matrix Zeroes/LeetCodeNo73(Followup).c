#define bool char
#define false 0
#define true 1

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	bool firstRowZero = false;
	bool firstColZero = false;

	// Check whether there is a 0 in first row or first column
	// If yes, set flag
	// If no, set corresponding row or column to 0 for later uses
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < *matrixColSize; j++){
			if(!matrix[i][j]){
				if(!i){
					firstRowZero = true;
				}
				if(!j){
					firstColZero = true;
				}
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	// Loop starts from 1 becuase if matrix[0][0] is 0, it will set the entire row/column to 0
	// Set the entire row to 0
	for(int i = 1; i < matrixSize; i++){
		if(!matrix[i][0]){
			for(int j = 0; j < *matrixColSize; j++){
				matrix[i][j] = 0;
			}
		}
	}
	// Set the entire column to 0
	for(int i = 1; i < *matrixColSize; i++){
		if(!matrix[0][i]){
			for(int j = 0; j < matrixSize; j++){
				matrix[j][i] = 0;
			}
		}
	}
	// If there is a zero in first row
	if(firstRowZero){
		for(int i = 0; i < *matrixColSize; i++){
			matrix[0][i] = 0;
		}
	}
	// If there is a zero in first column
	if(firstColZero){
		for(int i = 0; i < matrixSize; i++){
			matrix[i][0] = 0;
		}
	}
}