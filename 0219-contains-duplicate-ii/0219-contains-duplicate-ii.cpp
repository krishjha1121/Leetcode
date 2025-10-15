class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (st.count(nums[right])) return true;
            
            st.insert(nums[right]);
            
            if (right - left >= k) {
                st.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
