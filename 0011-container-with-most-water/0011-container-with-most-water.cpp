class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxi = 0;
        while(i < j){
            int len = j - i;
            int bre = min(height[i], height[j]);
            int area = 1LL * len * bre;
            maxi = max(area, maxi);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};