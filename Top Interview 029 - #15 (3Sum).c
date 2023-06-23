// Compare function for qsort()
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int resultSize = 10;
    int** result = (int**)malloc(sizeof(int*)*resultSize);
    *returnColumnSizes = (int*)malloc(sizeof(int)*resultSize);
    *returnSize = 0;
    
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 2; ++i) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int low = i + 1;
            int high = numsSize - 1;
            int sum = 0 - nums[i];
            while (low < high) {
                if (nums[low] + nums[high] == sum) {
                    // Resize result arrays if they are full
                    if (*returnSize >= resultSize) {
                        resultSize *= 2;
                        result = (int**)realloc(result, sizeof(int*)*resultSize);
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int)*resultSize);
                    }
                    int* triplet = (int*)malloc(sizeof(int)*3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[low];
                    triplet[2] = nums[high];
                    result[*returnSize] = triplet;
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++; high--;
                } else if (nums[low] + nums[high] < sum) {
                    low++;
                } else {
                    high--;
                }
            }
        }
    }

    return result;
}
