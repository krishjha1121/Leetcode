class Solution {
private:
    int findWaviness(int n){
        string s = to_string(n);
        if(s.size() < 3) return 0;
        int cnt = 0;
        for(int i = 1; i < s.size() - 1; i++){
            if(s[i] < s[i + 1] && s[i] < s[i - 1]) cnt++;
            else if(s[i] > s[i + 1] && s[i] > s[i - 1]) cnt++;
        }
        return cnt;
    }
public:
    int totalWaviness(int num1, int num2) {
        int totalVal = 0;
        for(int i = num1; i <= num2; i++){
            totalVal += findWaviness(i);
        }
        return totalVal;
    }
};