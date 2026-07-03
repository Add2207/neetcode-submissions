class Solution:
    def integerBreak(self, n: int) -> int:
        memo = {}
        def dp(num):
            if num in memo: return memo[num]
            if num == 1: return 1
            best = 0
            for i in range(1, num):
                best = max(best, i*(num-i), i*dp(num-i))
            memo[num] = best
            return best
        return dp(n)