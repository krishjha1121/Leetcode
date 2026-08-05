class Solution {
private:
    vector<string> temp;
    vector<vector<string>> ans;
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(string s, int i){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                temp.push_back(s.substr(i, j - i + 1));
                solve(s, j + 1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};