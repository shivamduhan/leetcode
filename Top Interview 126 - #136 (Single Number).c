int singleNumber(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i]; //xor will return 0 for same numbers and the number for single number
    }
    return result;
}
