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
    pair<int, int> solve(TreeNode* node, int &cnt){
        if(node == NULL) return {0, 0};

        pair<int, int> left = solve(node -> left, cnt);
        pair<int, int> right = solve(node -> right, cnt);

        int sum = node -> val + left.first + right.first;
        int nodes = 1 + left.second + right.second;
        if(sum / nodes == node -> val) cnt++;
        return {sum, nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};