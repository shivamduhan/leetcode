void rotate(int** matrix, int matrixSize, int* matrixColSize){
    //90 degree clockwise rotation is equivalent to tranpose the reverse
    //transpose the matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < matrixSize; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }   
    }
    //reverse the matrix
    for (int i = 0; i < matrixSize; i++){ //reverse each row
        for (int j = 0; j < matrixSize / 2; j++){ //go halfway and swap
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1]; //same row, swap first entry with last
            matrix[i][matrixSize - j - 1] = tmp; //swap last entry with first, to complete reverse
        }
    }
}
