class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        res = {}

        for i in nums:
            if i in res:
                res[i] += 1
                return True
                break
            else:
                res[i] = 1
        return False
            
