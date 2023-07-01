class Solution:
    def maxArea(self, height: List[int]) -> int:
        start, max_area, end = 0, 0, len(height) - 1
        while start < end:
            area = min(height[start], height[end]) * (end-start) #calc area, ensure +ve
            max_area = max(max_area, area)
            if height[start] < height[end]: #want to increase the min height so area is more
                start += 1
            else:
                end -= 1
        return max_area
