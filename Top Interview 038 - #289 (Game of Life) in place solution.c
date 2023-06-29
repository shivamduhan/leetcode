void gameOfLife(int** board, int boardSize, int* boardColSize){
    //define 8 directions for 8 neighbors in terms of lines eg. [-1,-1] for south west.
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    //use 4 states and bitwise operators to manipulate state.
    //state 0: dead(current)->dead(next)
    //state 1: alive(current)->dead(next)
    //state 2: dead(current)->alive(next)
    //state 3: alive(current)->alive(next)
    //note that current state is last bit


    for (int i = 0; i < boardSize; i++) { //go to next row
        for (int j = 0; j < boardColSize[0]; j++) { //go to next col of same row
            int live = 0;
            for (int k = 0; k < 8; k++) { //look at all 8 neighbors
                int nx = i + dx[k], ny = j + dy[k]; //get coordinate of current neighbor
                if (nx < 0 || nx >= boardSize || ny < 0 || ny >= boardColSize[0]) continue; //check out of bounds
                if (board[nx][ny] & 1) {live++;} //count current live neighbors 
            }
            if (live == 3 || (live == 2 && board[i][j])) {board[i][j] |= 2;} //compute next state, bitwise OR with 10 (cell will be 10 or 11, both alive)
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            board[i][j] >>= 1; //make next state current state i.e. implement all calc changes.
        }
    }
}
