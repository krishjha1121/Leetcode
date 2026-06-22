class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> st;
        int i = 0;
        int j = 0;
        int maxi = 0;
        while(j < n){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            int currLen = j - i + 1;
            maxi = max(maxi, currLen);
            j++;
        }
        return maxi;
    }
};