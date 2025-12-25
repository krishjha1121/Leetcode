class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<pair<int,int>> st;   
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first > prices[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = prices[i] - st.top().first;
            } else {
                res[i] = prices[i];
            }
            st.push({prices[i], i});
        }
        return res;
    }
};
