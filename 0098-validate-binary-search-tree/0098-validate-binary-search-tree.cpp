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
    bool isPossible(TreeNode* root, long long l, long long r){
        if(root == nullptr)  return true;
        if(root->val < r and root->val > l) return isPossible(root->left, l, root->val) 
        && isPossible(root->right, root->val, r);
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long min = LLONG_MIN, max = LLONG_MAX;
        return isPossible(root, min, max);
    }
};