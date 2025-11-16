class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
        long long inv2 = 500000004; // modular inverse of 2
        long long result = 0;

        int n = s.size();
        for(int i = 0; i < n;){
            if(s[i] == '1'){
                int j = i;
                while(j < n && s[j] == '1'){
                    j++;
                }
                long long len = j - i;  // length of consecutive ones
                long long val = (len % mod) * ((len + 1) % mod) % mod;
                val = val * inv2 % mod; // multiply by modular inverse instead of dividing
                result = (result + val) % mod;
                i = j;
            }
            else{
                i++;
            }
        }
        return (int)result;
    }
};
