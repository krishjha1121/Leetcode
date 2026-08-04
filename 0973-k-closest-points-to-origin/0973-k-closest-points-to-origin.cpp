class Solution {
private:
    int calcDistance(int x, int y) {
        return x * x + y * y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            int dist = calcDistance(points[i][0], points[i][1]);
            maxHeap.push({dist, i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            int pointIdx = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(points[pointIdx]);
        }
        return ans;
    }
};