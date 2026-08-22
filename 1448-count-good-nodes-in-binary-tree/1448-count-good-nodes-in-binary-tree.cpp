class Solution {
private:
    int dfs(TreeNode* node, int maxi) {
        if (!node) return 0;
        int ans = 0;
        if (node->val >= maxi) {
            ans = 1;
            maxi = node->val;
        }
        ans += dfs(node->left, maxi);
        ans += dfs(node->right, maxi);
        return ans;
    }

public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val);
    }
};