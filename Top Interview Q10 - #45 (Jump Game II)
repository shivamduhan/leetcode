int jump(int* nums, int numsSize){
    if (numsSize <=1) return 0;
    int jumps = 0, end = 0, furtherest = 0;
    for (int i =0; i < numsSize - 1; i++) {
        if (i + nums[i] > furtherest) {
            furtherest = i + nums[i];
        }
        if (i == end) {
            jumps++;
            end = furtherest;
        }
    }
    return jumps;

}
