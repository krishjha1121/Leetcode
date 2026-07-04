class Solution {
private:
    int ans = INT_MAX;
    int dfs(int node, vector<vector<pair<int,int>>>& adj,vector<int>& vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            ans = min(ans, it.second);
            if(!vis[it.first]){
                dfs(it.first, adj, vis);
            }
        }
        return ans;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            u--, v--;
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> vis(n, 0);
        return dfs(0, adj, vis);
    }
};