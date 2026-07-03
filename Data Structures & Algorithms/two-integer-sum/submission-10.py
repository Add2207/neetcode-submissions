class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hm = {}

        for i, num in enumerate(nums):
            complementary = target - num
            if complementary in hm:
                return [hm[complementary], i]
            hm[num] = i