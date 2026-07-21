class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int totalOnes = 0;
        for(auto c : s){
            if(c == '1') totalOnes++;
        }
        vector<pair<char, int>> v;
        for(auto c : s){
            if(v.empty() || v.back().first != c){
                v.push_back({c, 1});
            }else{
                v.back().second++;
            }
        }
        int ans = totalOnes;

        for (int i = 1; i + 1 < v.size(); i++) {
            if (v[i].first == '1' &&
                v[i - 1].first == '0' &&
                v[i + 1].first == '0') {

                ans = max(ans,totalOnes + v[i - 1].second + v[i + 1].second);
            }
        }

        return ans;
    }
};