class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";

        unordered_map<char,int> need;
        for (char c : t) need[c]++;

        int required = need.size();   // distinct chars in t
        int formed = 0;               // how many distinct chars are satisfied

        unordered_map<char,int> window;
        int left = 0, right = 0;
        int mini = INT_MAX;
        int startIdx = 0;

        while (right < n) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < mini) {
                    mini = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return (mini == INT_MAX) ? "" : s.substr(startIdx, mini);
    }
};
