class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixProduct(n, 0);
        suffixProduct[n - 2] = nums[n - 1];
        for(int i = n - 3; i >= 0; i--){
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }
        vector<int> res(n, 0);
        res[0] = suffixProduct[0];
        int currProduct = nums[0];
        for(int i = 1; i < n - 1; i++){
            res[i] = suffixProduct[i] * currProduct;
            currProduct *= nums[i];
        }
        res[n - 1] = currProduct;
        return res;
    }
};