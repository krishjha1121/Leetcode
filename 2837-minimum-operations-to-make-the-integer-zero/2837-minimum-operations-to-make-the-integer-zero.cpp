class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1; // start with 1 operation
        while (true) {
            long long x = num1 - (long long)num2 * k;
            
            if (x < k) { 
                // if remainder is less than k, impossible
                return -1;
            }
            
            if (k >= __builtin_popcountll(x)) {
                // valid: x can be represented with k powers of two
                return k;
            }
            
            k++;
        }
    }
};
