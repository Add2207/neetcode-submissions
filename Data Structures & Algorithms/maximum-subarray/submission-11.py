class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxi = nums[0]
        currSum = 0
        for num in nums:
            if currSum < 0:
                currSum = 0
            currSum += num
            maxi = max(currSum, maxi)
        return maxi
