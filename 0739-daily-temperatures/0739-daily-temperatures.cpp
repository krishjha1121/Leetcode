class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> res (n, 0);
        for(int i = n - 1; i >= 0 ; i--){
            if(i == n - 1) {
                st.push({temperatures[i], i});
                continue;
            }
            while(!st.empty()){
                if(st.top().first > temperatures[i]){
                    res[i] = -(i - st.top().second);
                    break;
                }
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};