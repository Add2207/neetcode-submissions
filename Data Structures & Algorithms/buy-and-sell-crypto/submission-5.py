class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = float('inf')
        maxP = 0

        for p in prices:
            if p < mini:
                mini = p
            maxP = max(maxP, p - mini)
        return maxP