class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "": return 0
        if len(s) == 1: return 1
        def isUnique(s:str):
            new_str = ""
            for i in range(0, len(s)):
                if i == len(s) - 1:
                    if s[i] not in new_str: return True
                if s[i] in new_str:
                    return False
                else: new_str += s[i]
        def count(s:str):
            window = len(s)
            length = window
            while(window > 1):
                start = 0
                end = window - 1
                while(length - start >= window):
                    if isUnique(s[start:end+1]):
                        return window
                    start += 1
                    end += 1
                window -= 1
            return 1
        return count(s)
         


print(Solution.lengthOfLongestSubstring(Solution, "abcabcbb"))