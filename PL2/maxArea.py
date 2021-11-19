class Solution:
    def maxArea(self, height) -> int:
        max = 0
        for h in range(len(height)):
            width = range(h+1,len(height))
            for w in width:
                area = min(height[h], height[w]) * (w-h)
                if area > max:
                    max = area
        return max

print(Solution.maxArea(Solution, ))