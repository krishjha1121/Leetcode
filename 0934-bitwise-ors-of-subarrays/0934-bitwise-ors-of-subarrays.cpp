class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for (int i = 0; i < arr.size(); ++i) {
            unordered_set<int> cur;
            cur.insert(arr[i]);
            result.insert(arr[i]);

            for (int x : prev) {
                cur.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }

            prev = cur;
        }

        return result.size();
    }
};
