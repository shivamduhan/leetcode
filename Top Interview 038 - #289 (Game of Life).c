void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (boardSize == 0) return;
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1}; //define directions to look for 8 neighbors i.e. 8 lines
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1}; //[-1, -1]: South-West, [0,1]: South, [1,-1]: South-East
    int copyBoard[boardSize][boardColSize[0]]; //boardsize is no. of rows

    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardColSize[0]; j++)
            copyBoard[i][j] = board[i][j]; //create a copy of the board

    for (int i = 0; i < boardSize; i++) { //iterate over rows
        for (int j = 0; j < boardColSize[0]; j++) { //iterate over cols
            int live = 0;
            for (int k = 0; k < 8; k++) { //look in 8 directions
                int nx = i + dx[k], ny = j + dy[k]; //add direction vectors to current location, calculate coordinates of particular neighbor
                if (nx < 0 || nx >= boardSize || ny < 0 || ny >= boardColSize[0]) continue; //out of bounds
                if (copyBoard[nx][ny] == 1) {live++;} //calculate number of live neighbors
            }
            if (copyBoard[i][j] == 1 && (live < 2 || live > 3)) board[i][j] = 0; //cell is dead (under/over population)
            if (copyBoard[i][j] == 0 && live == 3) board[i][j] = 1; //cell becomes alive if exactly 3 neighbors live
        }
    }
}
