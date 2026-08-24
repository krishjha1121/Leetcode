class Solution {
private:
    int findSquare(int n){
        int res = 0;
        while(n){
            int rem = n % 10;
            res += rem * rem;
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        }while(slow != fast);
        return slow == 1;
    }
};