class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxx = nums[0]
        currSum = 0

        for num in nums:
            if currSum < 0:
                currSum = 0
            currSum += num
            maxx = max(maxx, currSum)
        return maxx