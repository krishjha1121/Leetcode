class Solution {
private:
    void solve(string curr,map<string, multiset<string>>& adj,
    vector<string>& res) {
        while (!adj[curr].empty()) {
            string next = *adj[curr].begin();
            adj[curr].erase(adj[curr].begin());
            solve(next, adj, res);
        }
        res.push_back(curr);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        vector<string> res;
        solve("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }
};