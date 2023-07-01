class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first = second = float('inf') #init first 2 numbers in the subsequence
        for num in nums:
            if num <= first:
                first = num #num is smallest in subsequence
            elif num <= second:
                second = num #num is second in subsequence
            else:
                return True #num is third i.e. increasing triplet subsequence exists
        return False 
