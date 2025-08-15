class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
        }   

        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> res;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            res.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }
        }

        if(res.size() == n) return res;
        return {};
    }
};