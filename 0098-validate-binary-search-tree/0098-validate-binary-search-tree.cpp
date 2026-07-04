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
    void findInorder(TreeNode* node, vector<int>& in){
        if(!node) return;

        findInorder(node -> left, in);
        in.push_back(node -> val);
        findInorder(node -> right, in);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> inorder;
        findInorder(root, inorder);

        for(int i = 1; i < inorder.size(); i++){
            if(inorder[i] <= inorder[i - 1]) return false;
        }
        return true;
    }
};