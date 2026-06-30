class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int res = 0;

        map<char, int> mpp; // char freq

        int i = 0;
        int j = 0;

        while(j < n){
            mpp[s[j]]++;
            while(mpp.size() == 3 && i < n){
                res += (n - j);
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            j++;
        }

        return res;
    }
};