class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxx = nums[0]
        curr = 0

        for n in nums:
            if curr < 0:
                curr = 0
            curr += n
            maxx = max(maxx, curr)
        return maxx