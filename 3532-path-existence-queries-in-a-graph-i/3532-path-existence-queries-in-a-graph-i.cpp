class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n,vector<int>& nums,int maxDiff,
    vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        DSU dsu(n);
        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first <= maxDiff) {
                dsu.unite(arr[i].second, arr[i - 1].second);
            }
        }
        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));
        }
        return ans;
    }
};