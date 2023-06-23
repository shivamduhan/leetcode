class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1: return '' #no common divisor
        else: return str1[:gcd(len(str1),len(str2))]
    def gcd(a:int, b:int) -> int:
        while b:
            a, b = b, a % b
        return a

# class Solution:
 #   def gcdOfStrings(self, str1: str, str2: str) -> str:
  #      return "" if str1+str2 != str2+str1 else str1[:gcd(len(str1), len(str2))] 
