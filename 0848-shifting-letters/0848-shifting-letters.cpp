class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<long long> suff(n);
        suff[n - 1] = shifts[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + shifts[i];
        }
        for(int i = 0; i < n; i++) {
            int cnt = suff[i] % 26;
            s[i] = 'a' + ( (s[i] - 'a') + cnt ) % 26;
        }
        return s;
    }
};
