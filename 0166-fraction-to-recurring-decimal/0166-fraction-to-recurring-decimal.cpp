class Solution {
public:
    string fractionToDecimal(int n1, int d1) {
        string ans = "", temp = "";
        unordered_map<int, int> mp;
        
        if(!n1){
            return "0";
        }
        if(n1 > 0 and d1 < 0 or n1 < 0 and d1 > 0){
            temp += '-';
        }
        long long n = abs((long long)n1);
        long long d = abs((long long)d1);

        ans += to_string(n/d);
        n %= d;
        if(n){
            ans += '.';
            while(n and mp.find(n) == mp.end()){
                mp[n] = ans.size();
                n *= 10;
                ans += to_string(n/d);
                n %= d;
            }
            if(n){
                ans = ans.substr(0, mp[n]) + '(' + ans.substr(mp[n]) + ')';
            }
        }
        return temp + ans;
    }
};