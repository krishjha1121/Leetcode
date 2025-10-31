class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> pref(n);
        for(int i = 0; i < n; i++){
            pref[i] = capacity[i];
            if(i) pref[i] += pref[i - 1];
        }
        long long res = 0;
        map<pair<long long, long long>, int> mpp;
        for(int i = n - 1; i >= 0; i--){
            res += mpp[{capacity[i], pref[i] + 2 * capacity[i]}];
            if(i + 1 < n) mpp[{capacity[i + 1], pref[i + 1]}]++;
        }
        return res;
    }
};