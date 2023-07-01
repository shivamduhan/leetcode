class Solution:
    def compress(self, chars: List[str]) -> int:
        index = i = 0
        while i < len(chars):
            j = i
            while j < len(chars) and chars[j] == chars[i]:
                j += 1 #j keeps track of repetition
            chars[index] = chars[i] #get rid of all repeated chars
            index += 1
            if j - i > 1: #multiple repetition
                for digit in str(j-i):
                    chars[index] = digit #insert frequency
                    index += 1
            i = j #start counting freq of next letter
        return index
