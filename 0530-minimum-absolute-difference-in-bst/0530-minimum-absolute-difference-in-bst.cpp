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
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        inorder(root, values);

        for(auto it : values){
            cout << it << ' ';
        }
        
        int mini = INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            mini = min(mini, values[i] - values[i-1]);
        }
        
        return mini;
    }
};
