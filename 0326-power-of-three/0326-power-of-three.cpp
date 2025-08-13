class Solution {
private:
    bool solve(int n){
        if(n <= 0) return false;
        if(n == 1) return true;

        if(n % 3 != 0) return false;
        return solve(n / 3);
    }
public:
    bool isPowerOfThree(int n) {
        return solve(n);
    }
};