class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i, j, merge = 0, 0, ''
        while i < len(word1) or j < len(word2): #as long as we're still traversing the word, just add 1 char from each word and loop
            if i < len(word1): 
                merge += word1[i]
                i+=1
            if j < len(word2):
                merge += word2[j]
                j+=1
        return merge
