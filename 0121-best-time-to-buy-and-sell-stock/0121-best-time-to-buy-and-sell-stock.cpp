class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = prices[n - 1];
        int maxProfit = 0;
        for(int i = n - 1; i >= 0; i--){
            int profit = maxi - prices[i];
            maxProfit = max(profit, maxProfit);
            maxi = max(maxi, prices[i]);
        }
        return maxProfit;
    }
};