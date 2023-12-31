void sink(char ** grid, int gridSize, int * gridColSize, int i, int j){
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] == '0') {return;}
    grid[i][j] = '0'; //sink current land
    sink(grid, gridSize, gridColSize, i+1, j); //sink all connected land from same island
    sink(grid, gridSize, gridColSize, i-1, j);
    sink(grid, gridSize, gridColSize, i, j+1);
    sink(grid, gridSize, gridColSize, i, j-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int count = 0;
    for (int i = 0; i<gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') { //land encountered
                sink(grid, gridSize, gridColSize[i], i, j); //sink the entire island
                count++; //next time we encounter land its a differnt island
            }
        }
    }
    return count;
}
