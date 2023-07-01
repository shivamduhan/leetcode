class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero_pos = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[zero_pos] = nums[zero_pos], nums[i] #move 0 to the end
                zero_pos += 1 #check next index for swap
