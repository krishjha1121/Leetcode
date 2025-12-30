class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        map<int, set<int>> reachable;
        for(auto it : prerequisites){
            reachable[it[1]].insert(it[0]);
        }
        int n = numCourses;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                if(reachable[j].count(i)){
                    reachable[j].insert(reachable[i].begin() , reachable[i].end());
                }
            }
        }
        vector<bool> res;
        for(int i = 0 ; i < queries.size() ; i++){
            if(reachable[queries[i][1]].count(queries[i][0])){
                res.push_back(true);
            }
            else res.push_back(false);
        }
        return res;
    }
};