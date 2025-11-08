class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char, int> lastPosition; // char -> last Index
        for(int i = n - 1; i >= 0; i--){
            if(lastPosition.find(s[i]) == lastPosition.end()){
                lastPosition[s[i]] = i;
            } 
        }
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i < n){
            int idx = lastPosition[s[i]];
            j = idx;
            int curr = i;
            while(curr < j && j < n){
                curr++;
                if(lastPosition[s[curr]] > j){
                    j = lastPosition[s[curr]];
                }
            }
            res.push_back(j - i + 1);
            i = j + 1;
        }
        return res;

    }
};