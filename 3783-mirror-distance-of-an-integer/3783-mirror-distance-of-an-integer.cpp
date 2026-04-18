class Solution {
private:
    int findRev(int n){
        int temp = 0;
        while(n > 0){
            temp = temp * 10;
            temp += n % 10;
            n /= 10;
        }
        return temp;
    }
public:
    int mirrorDistance(int n) {
        int reverse = findRev(n);
        return abs(n - reverse);
    }
};