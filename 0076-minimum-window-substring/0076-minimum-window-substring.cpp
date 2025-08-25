class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";

        vector<int> need(256, 0);   // freq of characters in t
        for (char ch : t) need[ch]++;

        int required = m;           // total characters we need to match
        int left = 0, right = 0;
        int mini = INT_MAX;
        int startIdx = 0;

        while (right < n) {
            // Take current char into window
            if (need[s[right]] > 0) {
                required--;
            }
            need[s[right]]--;

            // When all chars matched
            while (required == 0) {
                if (right - left + 1 < mini) {
                    mini = right - left + 1;
                    startIdx = left;
                }

                // Try to shrink from left
                need[s[left]]++;
                if (need[s[left]] > 0) {
                    required++;
                }
                left++;
            }
            right++;
        }

        return (mini == INT_MAX) ? "" : s.substr(startIdx, mini);
    }
};
