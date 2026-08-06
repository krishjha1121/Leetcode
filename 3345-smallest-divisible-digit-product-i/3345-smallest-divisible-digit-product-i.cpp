class Solution {
private:
    int findProdOfDigits(int n){
        int prod = 1;
        while(n > 0){
            prod *= n % 10;
            n /= 10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        while(1){
            int prod = findProdOfDigits(n);
            if(prod % t == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};