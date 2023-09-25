int singleNumber(int* nums, int numsSize){
    int ones = 0, twos = 0, threes = 0; //keep track of numbers that appear once, twice, thrice
    for (int i = 0; i < numsSize; i++) {
        twos |= ones & nums[i]; // figure out elements that appear twice (ones & nums[i] finds new matches and twos |= adds them to existing set)
        ones ^= nums[i];        // update elements appearing once by Xoring
        threes = ones & twos;   // calculate 3 repetitions
        ones &= ~threes;        // if one number has appeared three times, we clear the corresponding bits in both ones and twos
        twos &= ~threes;
    }
    return ones;
}
