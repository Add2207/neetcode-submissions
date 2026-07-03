class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxx = nums[0]
        curSum = 0

        for num in nums:
            if curSum < 0:
                curSum = 0
            curSum += num
            maxx = max(maxx, curSum)
        return maxx