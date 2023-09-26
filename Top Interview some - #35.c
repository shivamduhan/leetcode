int searchInsert(int* nums, int numsSize, int target) {
    int mid = (numsSize-1)/2;
    for (int low = 0, high = numsSize-1; (high >= low)&&(nums[mid] != target); mid = (high+low)/2) {
        if (nums[mid] > target) {
            high = mid-1;
        } else {low = mid+1;}
    }
    return mid+(target > nums[mid]);
}
