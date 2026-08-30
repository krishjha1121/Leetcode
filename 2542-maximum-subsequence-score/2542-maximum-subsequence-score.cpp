class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        priority_queue<int,vector<int>,greater<int>> minHeap;
        long long sum = 0;
        long long ans = 0;

        for (auto& [num2, num1] : arr) {
            minHeap.push(num1);
            sum += num1;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                long long score = sum * num2;
                ans = max(ans, score);
            }
        }
        return ans;
    }
};