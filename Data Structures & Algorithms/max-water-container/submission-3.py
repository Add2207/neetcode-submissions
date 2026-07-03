class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        res, length = 0, r
        while l<=r:
            area = min(heights[l], heights[r])*length
            res = max(area, res)
            if heights[l] <= heights[r]:
                l += 1
                length -= 1
            else:
                r -= 1
                length -= 1
        return res