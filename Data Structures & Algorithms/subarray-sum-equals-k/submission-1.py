class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = curSum = 0
        seen = {0:1}
        for num in nums:
            curSum += num
            if curSum - k in seen:
                res += seen[curSum - k]
            seen[curSum] = 1 + seen.get(curSum, 0)
        return res