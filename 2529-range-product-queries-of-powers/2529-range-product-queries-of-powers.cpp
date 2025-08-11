class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {           
                powers.push_back(1 << i); 
            }
        }

        vector<int> pref(powers.size() + 1, 1);

        for (int i = 1; i <= (int)powers.size(); i++) {
            pref[i] = ( (1LL * pref[i - 1] % mod) * (powers[i - 1] % mod) ) % mod;
        }

        vector<int> ans;
        for (auto it : queries) {
            int left = it[0];
            int right = it[1];
            long long res = 1;
            for (int i = left; i <= right; i++) {
                res = ( (res % mod) * (powers[i] % mod) ) % mod;
            }
            ans.push_back((int)(res % mod)); 
        }

        return ans;
    }
};
