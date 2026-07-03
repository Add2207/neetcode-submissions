class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = INT_MIN;
        int min = prices[0];
        for(int i = 0; i < n; i++)
        {
            if(prices[i] < min) min = prices[i];
            if(prices[i] - min > maxP) maxP = prices[i] - min; 
        }
        if(maxP<0 || !maxP) return 0;
        else return maxP;
    }
};
