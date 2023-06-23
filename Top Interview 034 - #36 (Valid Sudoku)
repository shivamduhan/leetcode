 bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') { //non empty cell
                int num = board[i][j] - '0' - 1; //get a val b/w 0 and 8
                int k = (i/3)*3 + j/3; //determine index of 3x3 box
                if (row[i][num] || col[j][num] || box[k][num]) { //check if number has been used
                    return false;
                }
                row[i][num] = col[j][num] = box[k][num] = 1; //number has now been used in current row, col, box
            }
        }
    }
    return true;
} 
