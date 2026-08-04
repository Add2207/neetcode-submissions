class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        l = 0
        r = 0

        while (l and r) < len(prices):
            add = prices[r] - prices[l]
            profit = max(profit, add)
            if prices[l] > prices[r]:
                l = r
                r += 1
            r += 1
        return profit
