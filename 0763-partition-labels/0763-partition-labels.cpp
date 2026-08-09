class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        for(int i = s.size() - 1; i >= 0; i--){
            if(last[s[i] - 'a'] == -1){
                last[s[i] - 'a'] = i;
            }
        }
        vector<int> res;
        int i = 0;
        int lastIdx = 0;
        while(i < s.size()){
            int currChar = s[i];
            int currMaxi = last[currChar - 'a'];
            for(int j = i; j <= currMaxi; j++){
                int maxiIdx = last[s[j] - 'a'];
                currMaxi = max(currMaxi, maxiIdx);
            }
            res.empty() 
            ? res.push_back(currMaxi - lastIdx + 1) 
            : res.push_back(currMaxi - lastIdx);
            
            lastIdx = currMaxi;
            i = currMaxi + 1;
        }
        return res;
    }
};