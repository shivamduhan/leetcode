class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        flowerbed = [0] + flowerbed + [0] #edge cases padding
        for i in range(1, len(flowerbed) - 1): #traverse entire flowerbed
            if flowerbed[i-1] == flowerbed[i] == flowerbed[i+1] == 0: #current tile and adjacent tiles are empty
                flowerbed[i] = 1 #plant flower, update flowerbed
                count += 1 
        if count >= n: return True #can plant at least n flowers
        else: return False
