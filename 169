int majorityElement(int* nums, int numsSize){
    int cnt = 0; int test = 0;
    for (int i = 0; i < numsSize; i++){
        if (cnt == 0) {
            test = nums[i];
        }
        cnt += (nums[i] == test) ? 1 : -1;
    }
    return test;
}
