class Solution:
    def removeDuplicates(self, s: str) -> str:
        res = []
        length = len(s)
        for i in range(length):
            idx = len(res)
            if idx!=0 and s[i] == res[idx-1]:
                res.pop()
            else:
                res.append(s[i])
        return ''.join(res)
                        
print(Solution.removeDuplicates(Solution, "aaaaaaaa"))