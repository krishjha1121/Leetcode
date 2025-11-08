class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V); // Adjacency list for reverse graph
        vector<int> indegree(V, 0);
        // Reverse the graph
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i); // Reverse edge
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> res;
        // Push all nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        // Topological sort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        // Sort result to maintain order
        sort(res.begin(), res.end());
        return res;
    }
};
