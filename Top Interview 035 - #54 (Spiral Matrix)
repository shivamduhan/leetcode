int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *result = malloc(sizeof(int)*matrixSize * (*matrixColSize));
    int row_start = 0, row_end = matrixSize - 1;
    int col_start = 0, col_end = *matrixColSize - 1;
    *returnSize = 0;

    while (row_start <= row_end && col_start <= col_end) {
        for (int i = col_start; i <= col_end; i++) { //traverse first row forwards
            result[(*returnSize)++] = matrix[row_start][i]; //add first row to result
        }
        for (int i = row_start + 1; i <= row_end; i++) { //traverse last col downwards
            result[(*returnSize)++]=matrix[i][col_end];
        }
        if (row_start < row_end && col_start < col_end) { //till the spiral converges
            for (int i = col_end - 1; i > col_start; i--) { //traverse last row backwards
                result[(*returnSize)++] = matrix[row_end][i];
            }
            for (int i = row_end; i > row_start; i--) { //traverse first col upwards
                result[(*returnSize)++] = matrix[i][col_start];
            }
        }
        row_start++; //update boundaries of spiral
        row_end--;
        col_start++;
        col_end--;
    }
    return result;
}
