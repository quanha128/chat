class Solution:
    def longestCommonPrefix(self, strs) -> str:
        shortest = min(strs,key=len)
        n = len(shortest)
        OK = True
        for i in reversed(range(n)):
            OK = True
            for word in strs:
                if shortest[:i+1] not in word[:i+1]:
                    OK = False
                    break
            if OK:
                return shortest[:i+1]
        return ""

print(Solution.longestCommonPrefix(Solution, ["reflower","flow","flight"]))