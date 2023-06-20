int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* output = (int*) malloc(numsSize * sizeof(int));

    // Calculating product from the left
    output[0] = 1; //
    for(int i = 1; i < numsSize; ++i) {
        output[i] = nums[i-1] * output[i-1];
    }

    // Calculating product from the right
    int right = 1;
    for(int i = numsSize-1; i >= 0; --i) { //start from the end
        output[i] *= right; //multiply output by the numbers on the right
        right *= nums[i]; //
    }

    return output;
}

