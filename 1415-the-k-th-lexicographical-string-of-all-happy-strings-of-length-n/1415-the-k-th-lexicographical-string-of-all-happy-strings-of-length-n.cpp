class Solution {
private:
    void solve(string &curr, vector<string> &res, int n){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(curr, res, n);
            curr.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> res;
        solve(curr, res, n);
        if(res.size() < k) return "";
        return res[k - 1];
    }
};