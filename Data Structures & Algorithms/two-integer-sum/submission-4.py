class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        l = 0
        r = len(nums) - 1
        numsS = sorted(nums)

        while l < r:
            if (numsS[l] + numsS[r]) < (target):
                l = l + 1
            elif (numsS[l] + numsS[r]) > (target):
                r = r - 1
            elif (numsS[l] + numsS[r]) == (target):
                return [l, r]
            else:
                return [-1 , -1]
                