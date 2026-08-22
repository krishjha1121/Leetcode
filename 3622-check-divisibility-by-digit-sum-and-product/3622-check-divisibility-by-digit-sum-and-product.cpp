class Solution {
public:
    bool checkDivisibility(int n) {
        auto sumofDigit = [](int n) {
            int res = 0;
            while (n) {
                res += n % 10;
                n /= 10;
            }
            return res;
        };
        auto prodofDigit = [](int n) {
            int res = 1;
            while (n){
                res *= n % 10;
                n /= 10;
            }
            return res;
        };

        int x = sumofDigit(n);
        int y = prodofDigit(n);
        if(n % (x + y)) return false;
        return true;
    }
};