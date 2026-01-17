class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";
        for (char c : s) {
            if (c != '-') clean += toupper(c);
        }
        int n = clean.size();
        int first = n % k;
        if (first == 0) first = k;
        string res = clean.substr(0, first);
        for (int i = first; i < n; i += k) {
            res += "-";
            res += clean.substr(i, k);
        }
        return res;
    }
};
