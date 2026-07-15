class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            sumOdd += cnt;
            cnt++;
            sumEven += cnt;
            cnt++;
        }
        return __gcd(sumOdd, sumEven);
    }
};