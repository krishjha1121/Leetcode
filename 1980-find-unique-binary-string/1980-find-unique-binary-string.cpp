class Solution {
private:
    void solve(string &curr, vector<string> &res, int x){
        if(curr.length() == x){
            res.push_back(curr);
            return;
        }

        for(char ch = '0'; ch <= '1'; ch++){
            curr.push_back(ch);
            solve(curr, res, x);
            curr.pop_back();
        }
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int x = nums[0].size();
        unordered_set<string> st;

        for(auto &it : nums){
            st.insert(it);
        }

        vector<string> res;
        string curr = "";
        solve(curr , res, x);

        for(int i = 0; i < res.size(); i++){
            if(st.find(res[i]) == st.end()) return res[i];
        }
        return "";
    }
};