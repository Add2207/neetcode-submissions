class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        l = 0
        r = len(nums) - 1
        # nums = nums.sort()

        while l < r:
            if abs(nums[l] + nums[r]) < abs(target):
                l = l + 1
            elif abs(nums[l] + nums[r]) > abs(target):
                r = r - 1
            elif abs(nums[l] + nums[r]) == abs(target):
                return [l, r]
            else :
                return [-1, -1]