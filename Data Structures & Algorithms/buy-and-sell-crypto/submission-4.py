class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = float('inf')
        maxP = 0
        for price in prices:
            if price < mini:
                mini = price
            else:
                maxP = max(maxP, price - mini)
        return maxP