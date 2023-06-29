class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(reversed(s.split())) #split the string into words, then reverse them, then join
