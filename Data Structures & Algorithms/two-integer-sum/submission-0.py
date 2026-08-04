class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        l = 0
        r = len(nums) - 1
        # nums = nums.sort()

        while l < r:
            if nums[l] + nums[r] < target:
                l = l + 1
            elif nums[l] + nums[r] > target:
                r = r - 1
            elif nums[l] + nums[r] == target:
                return [l, r]
            else :
                return [-1, -1]