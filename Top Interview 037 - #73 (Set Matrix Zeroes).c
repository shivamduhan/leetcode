void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int isCol = 0; //use flag
    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {isCol = 1;} //if first col is 0, set flag to 1
        for (int j = 1; j < *matrixColSize; j++) {//go through entire row
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0; //set 1st row to be 0, will use as flag
                matrix[i][0] = 0; //set 1st col to be 0, will use as flag
            }
        }
    }
    for (int i = matrixSize - 1; i >= 0; i--) { //work backwards from last row
        for (int j = (*matrixColSize) - 1; j >= 1; j--) { //work backwards from last col
            if (matrix[i][0] == 0 || matrix[0][j] == 0) { //use first row/col = 0 as flag 
                matrix[i][j] = 0; //set the entire row to be 0
            }
        }
        if (isCol) {matrix[i][0] = 0;} //set first col to 0
    }
}
