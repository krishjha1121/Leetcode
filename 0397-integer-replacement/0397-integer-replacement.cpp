class Solution {
public:
    int findcnt(long long n){
        int cnt = 0;
        while(n > 1){
            if(n % 2 == 0){
                n /= 2;
            }
            else if((n + 1) % 4 == 0 && n + 1 != 4){
                n += 1;
            }
            else{
                n -= 1;
            }
            ++cnt;
        }
        return cnt;
    }
    int integerReplacement(int n) {
        return findcnt((long long)n);
    }
};