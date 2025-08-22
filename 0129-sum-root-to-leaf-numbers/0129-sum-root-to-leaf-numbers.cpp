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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;

        int totalSum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            auto node = it.first;
            int currSum = it.second;

            currSum = currSum * 10 + node -> val;

            if(!node -> left && !node -> right) totalSum += currSum;

            if(node -> left) q.push({node -> left, currSum});
            if(node -> right) q.push({node -> right, currSum});
        }

        return totalSum;
    }
};