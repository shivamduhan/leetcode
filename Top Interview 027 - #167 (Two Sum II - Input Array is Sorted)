int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int*result = (int*)malloc(sizeof(int)*2); //allocate returned array
    *returnSize = 2; //2 elements index 1 and index 2 in answer
    int start = 0, end = numbersSize - 1; //init 2 ptrs each end
    while (start < end) {
        int sum = numbers[start] + numbers[end]; //2 sum
        if (sum == target) {
            result[0] = start + 1; //return index added by 1
            result[1] = end + 1;
            return result;
        }
        else if (sum < target){
            start = start + 1; //we have to increase the sum. get a larger number
        }
        else {
            end = end - 1; //we need to decrease the sum. get a smaller number
        }
    }
    return result;
}
