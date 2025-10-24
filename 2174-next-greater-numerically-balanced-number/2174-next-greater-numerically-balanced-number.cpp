class Solution {
public:
    int nextBeautifulNumber(int n) {
        int x = n;
        while(1){
            string s = to_string(x);
            map<char, int> mpp;
            for(int i = 0; i < s.size(); i++){
                mpp[s[i]]++;
            }
            bool flag = true;
            for(auto it : mpp){
                int val = it.first - '0';
                int freq = it.second;
                if(val != freq) {
                    flag = false;
                    break;
                }
            }
            if(flag && x > n){
                return x;
            }
            x++;
        }

        return x;
    }
};