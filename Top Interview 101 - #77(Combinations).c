#include <stdlib.h>
#include <string.h>

// Variables used across multiple functions.
int n, k;
int* path;
int pathIndex;
int** combinations;
int combinationsSize;

// Recursive function to perform the backtracking.
void backtrack(int start) {
    // If we have added k numbers to the path, add it to the combinations.
    if(pathIndex == k) {
        combinations[combinationsSize] = (int*)malloc(k * sizeof(int));
        memcpy(combinations[combinationsSize++], path, k * sizeof(int));
        return;
    }
    // Try all other numbers greater than start.
    for(int i = start; i <= n; ++i) {
        // Add i to the path.
        path[pathIndex++] = i;
        // Continue trying other numbers.
        backtrack(i + 1);
        // Remove i from the path.
        --pathIndex;
    }
}

int** combine(int _n, int _k, int* returnSize, int** returnColumnSizes) {
    // Initialize global variables.
    n = _n;
    k = _k;
    path = (int*)malloc(k * sizeof(int));
    pathIndex = 0;
    combinations = (int**)malloc(10001 * sizeof(int*));
    combinationsSize = 0;
    // Start the backtracking with the number 1.
    backtrack(1);
    // Prepare the returnColumnSizes array.
    *returnColumnSizes = (int*)malloc(combinationsSize * sizeof(int));
    for(int i = 0; i < combinationsSize; ++i) {
        (*returnColumnSizes)[i] = k;
    }
    // Return the combinations.
    *returnSize = combinationsSize;
    return combinations;
}
