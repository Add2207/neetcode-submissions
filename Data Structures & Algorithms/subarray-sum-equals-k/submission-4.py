class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        seen = {0: 1}
        prefix = 0
        count = 0
        for num in nums:
            prefix += num
            if prefix - k in seen:
                count += seen[prefix-k]
            seen[prefix] = 1 + seen.get(prefix, 0)
        return count
            