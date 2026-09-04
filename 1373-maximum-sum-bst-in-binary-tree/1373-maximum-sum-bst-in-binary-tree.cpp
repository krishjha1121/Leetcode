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
public:
    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    int ans = 0;

    Info dfs(TreeNode* root) {
        if (root == nullptr) {
            return {
                true,
                INT_MAX,
                INT_MIN,
                0
            };
        }
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        if (left.isBST && right.isBST &&
            left.maxVal < root->val && root->val < right.minVal) {

            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);
            return {true, min(root->val, left.minVal),max(root->val, right.maxVal), sum};
        }
        return { false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};