int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2) return numsSize; //each unique element can appear at most twice
    int i =2;
    for (int j = 2; j < numsSize; j++) {
        if(nums[j] != nums[i-2]){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
