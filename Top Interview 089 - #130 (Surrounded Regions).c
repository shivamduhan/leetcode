void dfs(char** board, int boardSize, int* boardColSize, int i, int j) {
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || board[i][j] != 'O') {return;}
    board[i][j] = '1'; //mark all border and connected Os to 1
    dfs(board, boardSize, boardColSize, i-1, j); //Explore and find all connected Os
    dfs(board, boardSize, boardColSize, i, j - 1);
    dfs(board, boardSize, boardColSize, i, j+1);
    dfs(board, boardSize, boardColSize, i+1, j);
}
void solve(char** board, int boardSize, int* boardColSize){
    if (boardSize == 0) {return;}
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            bool edge = (i == 0) || (j == 0) || (i == boardSize - 1) || (j == boardColSize[i] - 1); //find border Os
            if (edge && board[i][j] == 'O') {dfs(board, boardSize, boardColSize, i, j);} //find connected Os
        }
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'O'){board[i][j] = 'X';} //These Os are not connected to any other Os, so X eats them
            if (board[i][j] == '1'){board[i][j] = 'O';} //1s represent Os connected to each other and/or border
        }
    }
}
