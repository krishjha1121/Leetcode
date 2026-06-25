class Solution {
private:
int expandAroundCenter(string s, int left, int right) {
    int cnt = 0;
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
        cnt++;
    }
    return cnt;
}  
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);

            cnt += odd;
            cnt += even;
        }
        return cnt;
    }
};