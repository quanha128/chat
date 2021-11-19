class Solution:
    def letterCombinations(self, digits: str):
        if digits == "":
            return []
        map_ = {
            '2': ['a','b','c'],
            '3': ['d','e','f'],
            '4': ['g','h','i'],
            '5': ['j','k','l'],
            '6': ['m','n','o'],
            '7': ['p','q','r','s'],
            '8': ['t','u','v'],
            '9': ['w','x','y','z'],
        }
        res = [""]
        for digit in digits:
            tmp = []
            for s in res:
                for i in (map_[digit]):
                    tmp.append(s + i)
            dum = res
            res = tmp
            tmp = dum

        return res
            
print(Solution.letterCombinations(Solution, "234"))