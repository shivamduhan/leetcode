class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True #trivially true        
        trav_s, trav_t = 0, 0
        while trav_t < len(t):
            if t[trav_t] == s[trav_s]: #1 char is same
                trav_s += 1 #next char in s
                if trav_s == len(s): #traversal of s is complete, everything matches
                    return True
            trav_t += 1 #compare next char in t
        return False
