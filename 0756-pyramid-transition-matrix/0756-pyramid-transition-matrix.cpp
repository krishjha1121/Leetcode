class Solution {
private:
    unordered_map<string, bool> memo;
    bool solve(string curr, int idx, map<string, vector<char>> &mpp, string next){
        if(curr.size() == 1) return true;
        string key = curr + "#" + to_string(idx) + "#" + next;
        if(memo.count(key)) return memo[key];
        if(idx == curr.size() - 1) return memo[key] = solve(next, 0, mpp, "");
        string temp = curr.substr(idx, 2);
        if(!mpp.count(temp)) return memo[key] = false;
        for(char &ch : mpp[temp]){
            next.push_back(ch);
            if(solve(curr, idx + 1, mpp, next)) return memo[key] = true;
            next.pop_back();
        }
        return memo[key] = false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, vector<char>> mpp;
        for(auto &s : allowed){
            string temp = s.substr(0, 2);
            mpp[temp].push_back(s[2]);
        }
        return solve(bottom, 0, mpp, "");
    }
};