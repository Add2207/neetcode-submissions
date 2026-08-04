class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        l = 0
        r = len(nums) - 1
        numsS = sorted(nums)

        while l < r:
            if abs(numsS[l] + numsS[r]) < abs(target):
                l = l + 1
            elif abs(numsS[l] + numsS[r]) > abs(target):
                r = r - 1
            elif abs(numsS[l] + numsS[r]) == abs(target):
                return [l, r]
            else :
                return [-1, -1]