class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string res = s;
        for (int k = 1; k <= n; k++) {
            string temp1 = s;
            string temp2 = s;
            // reverse first k characters
            reverse(temp1.begin(), temp1.begin() + k);
            res = min(res, temp1);
            // reverse last k characters
            reverse(temp2.end() - k, temp2.end());
            res = min(res, temp2);
        }
        return res;
    }
};