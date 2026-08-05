class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<int> vis(n, 0);
        dfs(k, vis, adj);

        vector<int> res;
        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            if(!vis[u] && vis[v]){
                for(int i = 0; i < n; i++){
                    res.push_back(i);
                }
                return res;
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};