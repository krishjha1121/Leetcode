class Solution {
private:
    const long long INF = 1e18;
    vector<long long> dijkstra(int src,
    vector<vector<pair<int, int>>> &graph) {
        int n = graph.size();
        vector<long long> dist(n, INF);
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
public:
    long long minimumWeight(int n,vector<vector<int>>& edges,int src1,int src2,int dest) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<pair<int, int>>> reverseGraph(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            graph[u].push_back({v, w});
            reverseGraph[v].push_back({u, w});
        }
        vector<long long> dist1 = dijkstra(src1, graph);
        vector<long long> dist2 = dijkstra(src2, graph);
        vector<long long> dist3 = dijkstra(dest, reverseGraph);
        long long answer = INF;
        for (int i = 0; i < n; i++) {
            if (dist1[i] == INF || dist2[i] == INF || dist3[i] == INF) {
                continue;
            }
            long long total = dist1[i] + dist2[i] + dist3[i];
            answer = min(answer, total);
        }
        return answer == INF ? -1 : answer;
    }
};