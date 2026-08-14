class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        map<char, int> mpp;
        int maxi = 0;
        while(j < n){
            mpp[s[j]]++;
            while(mpp[s[j]] > 2){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};