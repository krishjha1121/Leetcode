class Solution {
private:
    void solve(int currNum, int n, vector<int> &res){
        if(currNum > n) return;
        res.push_back(currNum);
        for(int i = 0; i <= 9; i++){
            int nextNum = currNum * 10 + i;
            if(nextNum > n) return; 
            solve(nextNum, n, res);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i <= 9; i++){
            solve(i, n, res);
        }
        return res;
    }
};
