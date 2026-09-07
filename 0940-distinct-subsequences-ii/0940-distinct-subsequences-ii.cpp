class Solution {
public:
    int distinctSubseqII(string s) {
        static const int MOD = 1e9 + 7;
        vector<long long> last(26, 0);

        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long newSubseq = (total + 1) % MOD;
            total = (total + newSubseq - last[idx] + MOD) % MOD;
            last[idx] = newSubseq;
        }
        return total;
    }
};