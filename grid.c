void sink(char ** grid, int gridSize, int * gridColSize, int i, int j){
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] == '0') {return;}
    grid[i][j] = '0';
    sink(grid, gridsize, gridColSize, i+1, j);
    sink(grid, gridsize, gridColSize, i, j+1);
    sink(grid, gridsize, gridColSize, i-1, j);
    sink(grid, gridsize, gridColSize, i, j-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int count = 0;
    for (int i = 0; i<gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                sink(grid, gridSize, gridColSize[i], i, j);
                count++;

            }
        }
    }
    return count;
}
