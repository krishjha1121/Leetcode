class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int n = s.size();
        string res(n, ' ');
        int i = 0, j = n - 1;
        for (int ch = 0; ch < 26; ch++) {
            while (freq[ch] >= 2) {
                res[i] = res[j] = char(ch + 'a');
                freq[ch] -= 2;
                i++;
                j--;
            }
        }
        for (int ch = 0; ch < 26; ch++) {
            if (freq[ch] == 1) {
                res[i] = char(ch + 'a');
                break;
            }
        }
        return res;
    }
};