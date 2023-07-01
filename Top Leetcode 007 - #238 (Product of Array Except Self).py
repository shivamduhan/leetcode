class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        answer = [0]*length
        answer[0] = 1 # init
        for i in range(1, length):
            answer[i] = nums[i-1]*answer[i-1] #left product
        right = 1
        for i in reversed(range(length)): #start from end
            answer[i] *= right #have already computed left prod, now multiply with right prod
            right *= nums[i] #update right prod
        return answer
