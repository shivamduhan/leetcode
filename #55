bool canJump(int* nums, int numsSize){
    int last_pos = numsSize - 1; //start from end
    for (int i = numsSize - 1; i >= 0; i--){ //iterate from end
        if (i + nums[i] >= last_pos){ //jump outside bounds
            last_pos = i; 
        }
    }
    return last_pos == 0; //can reach last index exactly

}
