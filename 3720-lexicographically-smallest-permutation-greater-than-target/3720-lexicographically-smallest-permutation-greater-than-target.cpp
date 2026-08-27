class Solution {
private:
    bool canFormGreater(const vector<int>& cnt, const string& target,int start) {
        return getMaxString(cnt) > target.substr(start);
    }

    string getMaxString(const vector<int>& cnt) {
        string res;
        for (int c = 25; c >= 0; c--){
            res += string(cnt[c], 'a' + c);
        }
        return res;
    }

    string getMinString(const vector<int>& cnt) {
        string res;
        for (int c = 0; c < 26; c++){
            res += string(cnt[c], 'a' + c);
        }
        return res;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s){
            cnt[c - 'a']++;
        }
        string res;
        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';
            if (cnt[x] > 0) {
                cnt[x]--;

                if (canFormGreater(cnt, target, i + 1)) {
                    res += target[i];
                    continue;
                }

                cnt[x]++;
            }
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] == 0) continue;
                cnt[c]--;
                res += char('a' + c);
                res += getMinString(cnt);
                return res;
            }
            return "";
        }
        return "";
    }

};