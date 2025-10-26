class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int max_len = 0;
        int max_freq = 0;
        unordered_map<char ,int> mpp;
        while(r < n){
            mpp[s[r]]++;
            max_freq = max(max_freq ,mpp[s[r]]);
            if((r - l + 1) - max_freq > k){
                mpp[s[l]]--;
                l++;
            }
            else{
                max_len = max(max_len , r - l + 1);
            }
            r++;
        }
        return max_len;
    }
};