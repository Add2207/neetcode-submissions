class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights) - 1
        length = r
        res = 0

        while l < r:
            area = min(heights[l], heights[r]) * length
            res = max(res, area)
            if heights[l] <= heights[r]:
                l += 1
                length -= 1
            else:
                r -= 1
                length -= 1
        return res