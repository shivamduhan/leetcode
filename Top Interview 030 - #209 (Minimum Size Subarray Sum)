int minSubArrayLen(int target, int* nums, int numsSize){
    int left = 0, minLen = INT_MAX, sum=0;
    for (int right = 0; right < numsSize; right++) { //expand subarray window
        sum += nums[right]; //expand towards the right
        while (sum >= target){ //we have to reduce the sum
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
            }
            sum -= nums[left++]; //keep getting rid of numbers on the left side. shrink from left to find smaller subarray for a given right boundary that still satisfies condition
        }        
    }
    return (minLen == INT_MAX) ? 0 : minLen; //return 0 in case subarray doesnt exist
}
//time complexity: O(n), space complexity: O(1)
