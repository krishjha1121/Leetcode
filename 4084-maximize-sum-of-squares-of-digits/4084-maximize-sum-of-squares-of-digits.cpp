class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num * 9 < sum) return "";
        string res = "";
        int currCharNum = 9;
        while(num > 0){
            if(sum >= currCharNum){
                res += currCharNum + '0';
                sum -= currCharNum;
                num--;
            }else{
                currCharNum--;
            }
        }
        if(sum > 0) return "";
        return res;
    }
};