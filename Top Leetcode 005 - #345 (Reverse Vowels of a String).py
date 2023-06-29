class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU') #define all vowels
        s = list(s) #create list
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] not in vowels: #go forwards from start
                i += 1
            elif s[j] not in vowels: #go backwards from end
                j -= 1
            else:
                s[i], s[j] = s[j], s[i] #swap, go till middle
                i += 1
                j -= 1
        return ''.join(s)
