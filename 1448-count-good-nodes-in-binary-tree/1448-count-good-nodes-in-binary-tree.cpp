/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* node, int &ans, int maxi) {
        if (!node) return;

        if (node->val >= maxi) {
            ans++;
            maxi = node->val; 
        }

        dfs(node->left, ans, maxi);
        dfs(node->right, ans, maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        dfs(root, ans, root->val);

        return ans;
    }
};